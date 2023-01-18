project('riscv-baremetal-hello-world',
        'c',
        version: '0.1',
        default_options: ['b_lundef=false']
        )

sources = files('src/main.c' ,'src/common.c', 'src/gpio.c', 'src/crt0.s' )

linker_script_flags = []

foreach entry : meson.get_cross_property('linker_paths', [''])
    if entry != ''
        linker_script_flags += '-L' + meson.source_root() / entry
    endif
endforeach

foreach entry : meson.get_cross_property('linker_scripts', [''])
    if entry != ''
        linker_script_flags += '-T' + entry
    endif
endforeach

exe_name = 'riscv-baremetal-hello-world'
elf_sufix = '.elf'
bin_sufix = '.bin'

exec = executable(exe_name + elf_sufix,
                          sources: sources,
                          link_args: linker_script_flags,
                          )

objcopy = meson.get_external_property('objcopy')
objcopy_args = meson.get_external_property('objcopy_args')

custom_target('bin',
          depends : exec,
          input : exec,
          output : exe_name + bin_sufix,
          command : [objcopy, '@INPUT@', objcopy_args, '@OUTPUT@'],
          build_by_default : true)
