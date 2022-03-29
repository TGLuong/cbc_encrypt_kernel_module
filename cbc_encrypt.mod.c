#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xb3753869, "module_layout" },
	{ 0x5ab5b891, "param_ops_int" },
	{ 0xde4c1a24, "param_ops_charp" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x7a4497db, "kzfree" },
	{ 0xef7d6f17, "crypto_destroy_tfm" },
	{ 0x94772f16, "crypto_skcipher_decrypt" },
	{ 0x6de13801, "wait_for_completion" },
	{ 0xe4fa414d, "crypto_skcipher_encrypt" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xc5850110, "printk" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x2a5499b0, "crypto_alloc_skcipher" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D3AA6065906F10067247321");
