@echo off
bcc32 -tW -WM main.c input.c debug.c timer.c display.c main_loop_thread.c graphics_thread.c data_sync_thread.c
