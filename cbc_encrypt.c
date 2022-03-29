#include <linux/moduleparam.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/crypto.h>
#include <linux/scatterlist.h>
#include <crypto/skcipher.h>


static int choice;
module_param(choice, int, S_IRUGO | S_IWUSR);

static char *key = "key";
module_param(key, charp, S_IRUGO | S_IWUSR);

static char *iv = "iv";
module_param(iv, charp, S_IRUGO | S_IWUSR);

static char *data = "data";
module_param(data, charp, S_IRUGO | S_IWUSR);


struct skcipher_def {
    struct scatterlist sg;
    struct crypto_skcipher *tfm;
    struct skcipher_request *req;
    struct crypto_wait wait;
};

static int encrypt(void)
{
    struct skcipher_def sk;
    struct crypto_skcipher *skcipher = NULL;
    struct skcipher_request *req = NULL;
    char copy_iv[16];
    int i;

    skcipher = crypto_alloc_skcipher("cbc-aes-aesni", 0, 0);
    req = skcipher_request_alloc(skcipher, GFP_KERNEL);
    crypto_skcipher_setkey(skcipher, key, 16);

    for (i = 0; i < 16; i++) {
        copy_iv[i] = iv[i];
    }

    sk.tfm = skcipher;
    sk.req = req;

    printk("ma hoa:\n");

    sg_init_one(&sk.sg, data, 16);
    skcipher_request_set_crypt(req, &sk.sg, &sk.sg, 16, iv);
    crypto_init_wait(&sk.wait);
    crypto_wait_req(crypto_skcipher_encrypt(sk.req), &sk.wait);

    printk("ban ma: %s\n", data);

    printk("\ngiai ma:\n");

    sg_init_one(&sk.sg, data, 16);
    skcipher_request_set_crypt(req, &sk.sg, &sk.sg, 16, copy_iv);
    crypto_init_wait(&sk.wait);
    crypto_wait_req(crypto_skcipher_decrypt(sk.req), &sk.wait);

    printk("ban ro: %s\n", data);



    if (skcipher)
        crypto_free_skcipher(skcipher);
    if (req)
        skcipher_request_free(req);
    return 0;
}

static int __init taes_init(void)
{
	printk("key: %s\n", key);	
    printk("iv: %s\n", iv);
    printk("ban ro: %s\n", data);
    encrypt();

	return 0;
}

static void __exit taes_exit(void){
    printk("thoat module\n");
}

module_init(taes_init);
module_exit(taes_exit);

MODULE_LICENSE("GPL");
