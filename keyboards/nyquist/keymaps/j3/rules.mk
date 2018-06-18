RGBLIGHT_ENABLE = yes
AUDIO_ENABLE = yes          # Audio output on port C6

MOUSEKEY_ENABLE = no        # Reduce Flash memory...
COMMAND_ENABLE = no         # Reduce Flash memory...
EXTRAKEY_ENABLE = no        # Reduce Flash memory...

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
