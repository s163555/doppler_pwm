# STM32F411RE Doppler firmware
Firmware for Doppler project (BMM Laboratory). Developed spring 2023 for MSEE thesis built on top of Zephyr RTOS.

## Getting Started

Before getting started, make sure you have a proper Zephyr development
environment. You can follow the official
[Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html).

### Initialization

The first step is to initialize the `dopper_pwm` workspace folder where the
source and all Zephyr modules will be cloned. You can do that by running:

```shell
# initialize doppler_pwm workspace
west init -m https://github.com/s163555/doppler_pwm --mr main dopper_pwm
# update modules
cd doppler_pwm
west update
```

### Build & Run

The application can be built by running:

```shell
west build -b $BOARD doppler_pwm
```

where `$BOARD` is the target board (see `boards`).

Once you have built the application you can flash it by running:

```shell
west flash
```

#### Inquiries

Questions can be forwarded to e-mail: jhinrichs[at]kaist.ac.kr.