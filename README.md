# Simple Digital Watchface for Pebble

A clean and simple digital watchface for Pebble smartwatches.

## Features

- Large, easy-to-read time display (12/24 hour format based on watch settings)
- Date display (day of week, day, month)
- Battery percentage indicator

## Building

1. Install the [Pebble SDK](https://developer.pebble.com/sdk/)
2. Build the watchface:
   ```bash
   pebble build
   ```

## Running on Emulator

To test the watchface on the Pebble emulator:

1. Build the watchface (see above)
2. Install on emulator:
   ```bash
   pebble install --emulator aplite
   ```
   Or for Pebble Time (color):
   ```bash
   pebble install --emulator basalt
   ```
   Or for Pebble Time Round:
   ```bash
   pebble install --emulator chalk
   ```

3. The emulator window will open automatically showing your watchface

**Note:** If the emulator doesn't launch automatically, you may need to start it manually. The `pebble install --emulator` command should handle this, but if needed, you can also use the Pebble SDK's emulator controls like `pebble emu-control` to interact with the emulator.

## Installing on Physical Watch

Install on your watch:
```bash
pebble install --phone <your-phone-ip>
```

## Requirements

- Pebble SDK 3.0 or later
- Compatible with Pebble Classic, Pebble Time, and Pebble Time Round

