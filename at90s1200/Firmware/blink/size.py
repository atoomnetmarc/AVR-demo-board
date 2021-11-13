Import("env", "projenv")

env.AddPostAction(
	"$BUILD_DIR/${PROGNAME}.elf",
	env.VerboseAction("avr-size --mcu=${BOARD_MCU} -C \"$BUILD_DIR/${PROGNAME}.elf\"",
	"")
)
