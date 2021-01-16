@echo off
bcc32 -tW -WM -w-wpar main.c debug.c timer.c main_loop_thread.c graphics_thread.c data_sync_thread.c
