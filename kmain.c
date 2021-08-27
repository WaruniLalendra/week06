
#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"

    
void kmain(multiboot_info_t *mbinfo){

    multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
    multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
    unsigned int address_of_module = modules->mod_start;
	
	if(mbinfo->mods_count == 1){
        char msg[] = "Module is loaded correctly.\n";
		fb_write(msg, sizeof(msg));
        
        typedef void (*call_module_t)(void);
        /* ... */
        call_module_t start_program = (call_module_t) address_of_module;
        start_program();
        /* we'll never get here, unless the module code returns */
    }else{
        char errorMsg[] = "Error: Number of modules loaded is not equal to 1.\n";
        fb_write(errorMsg, sizeof(errorMsg));
    }


}
    

    /*mutiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
    unsigned int address_of_module = mbinfo->mods_addr;
    //module_t* modules = (module_t*) mbinfo->mods_addr;       
    //unsigned int address_of_module = modules->mod_start;
     
    typedef void (*call_module_t)(void);
    call_module_t start_program = (call_module_t) address_of_module;
    start_program(); 

   //multiboot_info_t *mbinfo	

    char msg[] = "KleinOS";
    unsigned char scancode,ascii;
    char asciicode[1];
   
    segments_install_gdt();
    serial_write(msg, sizeof(msg));
    fb_write(msg, sizeof(msg));
    interrupts_install_idt();
    scancode = keyboard_read_scan_code();
    ascii = keyboard_scan_code_to_ascii(scancode);
    asciicode[0] = ascii;
    serial_write(asciicode, sizeof(asciicode));*/
    

