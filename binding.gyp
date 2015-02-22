{
  "targets": [
    {
      "target_name": "rpi_rgb_led_matrix",
      "sources": [
        "node-rpi-rgb-led-matrix.cc",
        "lib/gpio.cc",
        "lib/led-matrix.cc",
        "lib/framebuffer.cc",
        "lib/thread.cc"
      ],
      "cflags_cc": [ "-Llib -lrgbmatrix -lrt -lm -lpthread" ],
      "include_dirs" : [
        "include",
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
