project('KittehWatchOS', 'c')

cc = meson.get_compiler('c')
pkg = import('pkgconfig')



sources = [
	'src/main.c',
]

includes = [
  include_directories('.'),
  include_directories('src'),
  include_directories('src/lvconf'),
  include_directories('deps'),
]


sources_platform_pinetime = [
  'src/platform/PineTime/FreeRTOS/port.c',
  'src/platform/PineTime/FreeRTOS/port_cmsis.c',
  'src/platform/PineTime/FreeRTOS/port_cmsis_systick.c',
  'src/platform/PineTime/backlight/backlight.c',

]

includes_platform_pinetime = [
  include_directories('src/platform/PineTime/FreeRTOS'),
  include_directories('src/platform/PineTime'),
]


sources_platform_linux = [
  'src/platform/Linux/FreeRTOS/port.c',
  'src/platform/Linux/FreeRTOS/heap_4.c',
  'src/platform/Linux/backlight/backlight.c',
  'src/platform/Linux/display/display.c',
  'deps/lv_drivers/display/monitor.c',
  'deps/lv_drivers/indev/mouse.c',
]

includes_platform_linux = [
  include_directories('src/platform/Linux/FreeRTOS'),
  include_directories('src/platform/Linux'),

]


if get_option('linux')
sources += sources_platform_linux
includes += includes_platform_linux
else
sources += sources_platform_pinetime
includes += includes_platform_pinetime
endif

cflags = [
  '-Wall',
  '-fvisibility=hidden',
]


deps = [
#cc.find_library('nosys', required : false),
]

lvgl_sources = [
    'deps/lvgl/src/lv_misc/lv_bidi.c',
    'deps/lvgl/src/lv_misc/lv_area.c',
    'deps/lvgl/src/lv_misc/lv_ll.c',
    'deps/lvgl/src/lv_misc/lv_async.c',
    'deps/lvgl/src/lv_misc/lv_txt.c',
    'deps/lvgl/src/lv_misc/lv_utils.c',
    'deps/lvgl/src/lv_misc/lv_templ.c',
    'deps/lvgl/src/lv_misc/lv_txt_ap.c',
    'deps/lvgl/src/lv_misc/lv_gc.c',
    'deps/lvgl/src/lv_misc/lv_math.c',
    'deps/lvgl/src/lv_misc/lv_mem.c',
    'deps/lvgl/src/lv_misc/lv_task.c',
    'deps/lvgl/src/lv_misc/lv_fs.c',
    'deps/lvgl/src/lv_misc/lv_printf.c',
    'deps/lvgl/src/lv_misc/lv_log.c',
    'deps/lvgl/src/lv_misc/lv_debug.c',
    'deps/lvgl/src/lv_misc/lv_color.c',
    'deps/lvgl/src/lv_misc/lv_anim.c',
    'deps/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.c',
    'deps/lvgl/src/lv_draw/lv_draw_arc.c',
    'deps/lvgl/src/lv_draw/lv_draw_triangle.c',
    'deps/lvgl/src/lv_draw/lv_img_decoder.c',
    'deps/lvgl/src/lv_draw/lv_draw_line.c',
    'deps/lvgl/src/lv_draw/lv_draw_blend.c',
    'deps/lvgl/src/lv_draw/lv_draw_rect.c',
    'deps/lvgl/src/lv_draw/lv_img_buf.c',
    'deps/lvgl/src/lv_draw/lv_img_cache.c',
    'deps/lvgl/src/lv_draw/lv_draw_img.c',
    'deps/lvgl/src/lv_draw/lv_draw_label.c',
    'deps/lvgl/src/lv_draw/lv_draw_mask.c',
    'deps/lvgl/src/lv_core/lv_group.c',
    'deps/lvgl/src/lv_core/lv_obj.c',
    'deps/lvgl/src/lv_core/lv_disp.c',
    'deps/lvgl/src/lv_core/lv_style.c',
    'deps/lvgl/src/lv_core/lv_refr.c',
    'deps/lvgl/src/lv_core/lv_indev.c',
    'deps/lvgl/src/lv_themes/lv_theme_mono.c',
    'deps/lvgl/src/lv_themes/lv_theme_template.c',
    'deps/lvgl/src/lv_themes/lv_theme_empty.c',
    'deps/lvgl/src/lv_themes/lv_theme_material.c',
    'deps/lvgl/src/lv_themes/lv_theme.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_40.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_12_subpx.c',
    'deps/lvgl/src/lv_font/lv_font_simsun_16_cjk.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_16.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_26.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_24.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_18.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_30.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_28.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_46.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_48.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_36.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_34.c',
    'deps/lvgl/src/lv_font/lv_font_fmt_txt.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_32.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_14.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_22.c',
    'deps/lvgl/src/lv_font/lv_font_unscii_8.c',
    'deps/lvgl/src/lv_font/lv_font_loader.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_38.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_28_compressed.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_44.c',
    'deps/lvgl/src/lv_font/lv_font_dejavu_16_persian_hebrew.c',
    'deps/lvgl/src/lv_font/lv_font.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_20.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_42.c',
    'deps/lvgl/src/lv_font/lv_font_montserrat_12.c',
    'deps/lvgl/src/lv_widgets/lv_keyboard.c',
    'deps/lvgl/src/lv_widgets/lv_objmask.c',
    'deps/lvgl/src/lv_widgets/lv_tabview.c',
    'deps/lvgl/src/lv_widgets/lv_objx_templ.c',
    'deps/lvgl/src/lv_widgets/lv_dropdown.c',
    'deps/lvgl/src/lv_widgets/lv_spinbox.c',
    'deps/lvgl/src/lv_widgets/lv_checkbox.c',
    'deps/lvgl/src/lv_widgets/lv_table.c',
    'deps/lvgl/src/lv_widgets/lv_roller.c',
    'deps/lvgl/src/lv_widgets/lv_imgbtn.c',
    'deps/lvgl/src/lv_widgets/lv_linemeter.c',
    'deps/lvgl/src/lv_widgets/lv_canvas.c',
    'deps/lvgl/src/lv_widgets/lv_line.c',
    'deps/lvgl/src/lv_widgets/lv_list.c',
    'deps/lvgl/src/lv_widgets/lv_chart.c',
    'deps/lvgl/src/lv_widgets/lv_led.c',
    'deps/lvgl/src/lv_widgets/lv_arc.c',
    'deps/lvgl/src/lv_widgets/lv_cpicker.c',
    'deps/lvgl/src/lv_widgets/lv_page.c',
    'deps/lvgl/src/lv_widgets/lv_label.c',
    'deps/lvgl/src/lv_widgets/lv_cont.c',
    'deps/lvgl/src/lv_widgets/lv_btnmatrix.c',
    'deps/lvgl/src/lv_widgets/lv_switch.c',
    'deps/lvgl/src/lv_widgets/lv_gauge.c',
    'deps/lvgl/src/lv_widgets/lv_slider.c',
    'deps/lvgl/src/lv_widgets/lv_img.c',
    'deps/lvgl/src/lv_widgets/lv_textarea.c',
    'deps/lvgl/src/lv_widgets/lv_msgbox.c',
    'deps/lvgl/src/lv_widgets/lv_calendar.c',
    'deps/lvgl/src/lv_widgets/lv_bar.c',
    'deps/lvgl/src/lv_widgets/lv_spinner.c',
    'deps/lvgl/src/lv_widgets/lv_btn.c',
    'deps/lvgl/src/lv_widgets/lv_win.c',
    'deps/lvgl/src/lv_widgets/lv_tileview.c',
    'deps/lvgl/src/lv_hal/lv_hal_tick.c',
    'deps/lvgl/src/lv_hal/lv_hal_indev.c',
    'deps/lvgl/src/lv_hal/lv_hal_disp.c',
]

lvgl_includes = [
  include_directories('deps'),
]

lvgl_cflags = [
	'-Wall',
	'-fvisibility=hidden',
  '-DLV_CONF_INCLUDE_SIMPLE',
]

sources += lvgl_sources
includes += lvgl_includes
cflags += lvgl_cflags

sdk_sources = [
                'deps/nRF5_SDK/modules/nrfx/mdk/system_nrf52.c',
                'deps/nRF5_SDK/modules/nrfx/mdk/gcc_startup_nrf52.S',
            'deps/nRF5_SDK/components/boards/boards.c',
            'deps/nRF5_SDK/integration/nrfx/legacy/nrf_drv_clock.c',
            'deps/nRF5_SDK/modules/nrfx/drivers/src/nrfx_clock.c',
            'deps/nRF5_SDK/modules/nrfx/drivers/src/nrfx_gpiote.c',
            'deps/nRF5_SDK/modules/nrfx/soc/nrfx_atomic.c',
            'deps/nRF5_SDK/modules/nrfx/drivers/src/nrfx_saadc.c',
#      'deps/nRF5_SDK/external/freertos/source/croutine.c',
#      'deps/nRF5_SDK/external/freertos/source/event_groups.c',
#      'deps/nRF5_SDK/external/freertos/source/portable/MemMang/heap_1.c',
#      'deps/nRF5_SDK/external/freertos/source/list.c',
#      'deps/nRF5_SDK/external/freertos/source/queue.c',
#      'deps/nRF5_SDK/external/freertos/source/stream_buffer.c',
#      'deps/nRF5_SDK/external/freertos/source/tasks.c',
#      'deps/nRF5_SDK/external/freertos/source/timers.c',
      'deps/nRF5_SDK/components/libraries/timer/app_timer_freertos.c',
            'deps/nRF5_SDK/components/libraries/atomic/nrf_atomic.c',
            'deps/nRF5_SDK/components/libraries/balloc/nrf_balloc.c',
            'deps/nRF5_SDK/components/libraries/util/nrf_assert.c',
            'deps/nRF5_SDK/components/libraries/util/app_error.c',
            'deps/nRF5_SDK/components/libraries/util/app_error_weak.c',
            'deps/nRF5_SDK/components/libraries/util/app_error_handler_gcc.c',
            'deps/nRF5_SDK/components/libraries/util/app_util_platform.c',
            'deps/nRF5_SDK/components/libraries/log/src/nrf_log_backend_rtt.c',
            'deps/nRF5_SDK/components/libraries/log/src/nrf_log_backend_serial.c',
            'deps/nRF5_SDK/components/libraries/log/src/nrf_log_default_backends.c',
            'deps/nRF5_SDK/components/libraries/log/src/nrf_log_frontend.c',
            'deps/nRF5_SDK/components/libraries/log/src/nrf_log_str_formatter.c',
            'deps/nRF5_SDK/components/libraries/memobj/nrf_memobj.c',
            'deps/nRF5_SDK/components/libraries/ringbuf/nrf_ringbuf.c',
            'deps/nRF5_SDK/components/libraries/strerror/nrf_strerror.c',
            'deps/nRF5_SDK/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c',
            'deps/nRF5_SDK/external/segger_rtt/SEGGER_RTT.c',
            'deps/nRF5_SDK/external/segger_rtt/SEGGER_RTT_printf.c',
           'deps/nRF5_SDK/external/utf_converter/utf.c',
            'deps/nRF5_SDK/external/fprintf/nrf_fprintf.c',
            'deps/nRF5_SDK/external/fprintf/nrf_fprintf_format.c',
      'deps/nRF5_SDK/modules/nrfx/drivers/src/nrfx_twi.c',
            'deps/nRF5_SDK/components/libraries/scheduler/app_scheduler.c',
            'deps/nRF5_SDK/components/libraries/fifo/app_fifo.c',
            'deps/nRF5_SDK/components/libraries/uart/app_uart_fifo.c',
      'deps/nRF5_SDK/components/libraries/button/app_button.c',
      'deps/nRF5_SDK/components/libraries/gpiote/app_gpiote.c',
            'deps/nRF5_SDK/components/libraries/bsp/bsp.c',
                'deps/nRF5_SDK/components/libraries/bsp/bsp_btn_ant.c',
                'deps/nRF5_SDK/components/libraries/bsp/bsp_nfc.c',
            'deps/nRF5_SDK/components/libraries/fds/fds.c',
            'deps/nRF5_SDK/components/libraries/fstorage/nrf_fstorage.c',
            'deps/nRF5_SDK/components/libraries/fstorage/nrf_fstorage_sd.c',
            'deps/nRF5_SDK/components/libraries/fstorage/nrf_fstorage_nvmc.c',
  'deps/nRF5_SDK/components/softdevice/common/nrf_sdh.c',
  'deps/nRF5_SDK/components/softdevice/common/nrf_sdh_ble.c',
  'deps/nRF5_SDK/components/softdevice/common/nrf_sdh_soc.c',
  'deps/nRF5_SDK/components/libraries/experimental_section_vars/nrf_section_iter.c',
  'deps/nRF5_SDK/components/libraries/atomic_fifo/nrf_atfifo.c',



]

sdk_includes = [ 
            'deps/nRF5_SDK/components/toolchain/cmsis/include',

                'deps/nRF5_SDK/components/softdevice/s132/headers',
                'deps/nRF5_SDK/components/softdevice/s132/headers/nrf52',
          'deps/nRF5_SDK/components/drivers_nrf/nrf_soc_nosd',
            'deps/nRF5_SDK/components',
            'deps/nRF5_SDK/components/boards',
            'deps/nRF5_SDK/components/softdevice/common',
            'deps/nRF5_SDK/integration/nrfx',
            'deps/nRF5_SDK/integration/nrfx/legacy',
            'deps/nRF5_SDK/modules/nrfx',
            'deps/nRF5_SDK/modules/nrfx/drivers/include',
            'deps/nRF5_SDK/modules/nrfx/hal',
            'deps/nRF5_SDK/modules/nrfx/mdk',
            'deps/nRF5_SDK/components/toolchain/cmsis/include',
            'deps/nRF5_SDK/components/libraries/atomic',
            'deps/nRF5_SDK/components/libraries/atomic_fifo',
            'deps/nRF5_SDK/components/libraries/atomic_flags',
            'deps/nRF5_SDK/components/libraries/balloc',
            'deps/nRF5_SDK/components/libraries/bootloader/ble_dfu',
            'deps/nRF5_SDK/components/libraries/cli',
            'deps/nRF5_SDK/components/libraries/crc16',
            'deps/nRF5_SDK/components/libraries/crc32',
            'deps/nRF5_SDK/components/libraries/crypto',
            'deps/nRF5_SDK/components/libraries/csense',
            'deps/nRF5_SDK/components/libraries/csense_drv',
            'deps/nRF5_SDK/components/libraries/delay',
            'deps/nRF5_SDK/components/libraries/ecc',
            'deps/nRF5_SDK/components/libraries/experimental_section_vars',
            'deps/nRF5_SDK/components/libraries/experimental_task_manager',
            'deps/nRF5_SDK/components/libraries/fds',
            'deps/nRF5_SDK/components/libraries/fstorage',
            'deps/nRF5_SDK/components/libraries/gfx',
            'deps/nRF5_SDK/components/libraries/gpiote',
            'deps/nRF5_SDK/components/libraries/hardfault',
            'deps/nRF5_SDK/components/libraries/hci',
            'deps/nRF5_SDK/components/libraries/led_softblink',
            'deps/nRF5_SDK/components/libraries/log',
            'deps/nRF5_SDK/components/libraries/log/src',
            'deps/nRF5_SDK/components/libraries/low_power_pwm',
            'deps/nRF5_SDK/components/libraries/mem_manager',
            'deps/nRF5_SDK/components/libraries/memobj',
            'deps/nRF5_SDK/components/libraries/mpu',
            'deps/nRF5_SDK/components/libraries/mutex',
            'deps/nRF5_SDK/components/libraries/pwm',
            'deps/nRF5_SDK/components/libraries/pwr_mgmt',
            'deps/nRF5_SDK/components/libraries/queue',
            'deps/nRF5_SDK/components/libraries/ringbuf',
            'deps/nRF5_SDK/components/libraries/scheduler',
            'deps/nRF5_SDK/components/libraries/sdcard',
            'deps/nRF5_SDK/components/libraries/slip',
            'deps/nRF5_SDK/components/libraries/sortlist',
            'deps/nRF5_SDK/components/libraries/spi_mngr',
            'deps/nRF5_SDK/components/libraries/stack_guard',
            'deps/nRF5_SDK/components/libraries/strerror',
            'deps/nRF5_SDK/components/libraries/svc',
            'deps/nRF5_SDK/components/libraries/timer',
            'deps/nRF5_SDK/components/libraries/usbd',
            'deps/nRF5_SDK/components/libraries/usbd/class/audio',
            'deps/nRF5_SDK/components/libraries/usbd/class/cdc',
            'deps/nRF5_SDK/components/libraries/usbd/class/cdc/acm',
            'deps/nRF5_SDK/components/libraries/usbd/class/hid',
            'deps/nRF5_SDK/components/libraries/usbd/class/hid/generic',
            'deps/nRF5_SDK/components/libraries/usbd/class/hid/kbd',
            'deps/nRF5_SDK/components/libraries/usbd/class/hid/mouse',
            'deps/nRF5_SDK/components/libraries/usbd/class/msc',
            'deps/nRF5_SDK/components/libraries/util',
            'deps/nRF5_SDK/external/segger_rtt/',
            'deps/nRF5_SDK/external/fprintf/',
      'deps/nRF5_SDK/external/thedotfactory_fonts',
            'deps/nRF5_SDK/components/libraries/scheduler',
            'deps/nRF5_SDK/components/libraries/fifo',
            'deps/nRF5_SDK/components/libraries/uart',
      'deps/nRF5_SDK/components/libraries/button',
      'deps/nRF5_SDK/components/libraries/gpiote',
            'deps/nRF5_SDK/components/libraries/bsp',
            'deps/nRF5_SDK/components/ble/nrf_ble_gatt',
            'deps/nRF5_SDK/components/ble/ble_advertising',
            'deps/nRF5_SDK/components/ble/peer_manager',
            'deps/nRF5_SDK/components/libraries/fds',
            'deps/nRF5_SDK/components/libraries/fstorage',
            'deps/nRF5_SDK/components/libraries/experimental_section_vars',




]

sdk_cflags = [
    '-DFLOAT_ABI_HARD',
    '-DNRF52832_XXAA',
    '-DSOFTDEVICE_PRESENT',
    '-DS132',
    '-DNRF_SD_BLE_API_VERSION=6',
    '-DBLE_STACK_SUPPORT_REQD',
    '-DBOARD_PCA10040',

]


if not get_option('linux')
sources += sdk_sources
includes += sdk_includes
cflags += sdk_cflags
endif

if get_option('linux')
deps += cc.find_library('pthread', required : true)
deps += cc.find_library('rt', required : true)
deps += cc.find_library('SDL2', required : true)

endif


freertos_sources = [
    'deps/FreeRTOS/list.c',
    'deps/FreeRTOS/stream_buffer.c',
    'deps/FreeRTOS/tasks.c',
    'deps/FreeRTOS/queue.c',
    'deps/FreeRTOS/croutine.c',
    'deps/FreeRTOS/timers.c',
    'deps/FreeRTOS/event_groups.c',
]

freertos_includes = [
    'deps/FreeRTOS/include',
]

sources += freertos_sources
includes += freertos_includes


link_args = [

]


if not get_option('linux')
link_args += ['-Tgcc_nrf52.ld', '-L..', '-L../deps/nRF5_SDK/modules/nrfx/mdk']
endif

executable('KittehWatchOS',
	name_prefix: '',
	install: false,
	c_args: cflags,
  link_args: link_args,
	sources: sources,
	include_directories: includes,
	dependencies: deps)
