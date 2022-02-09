/*
 * main.h
 *
 * Created: 9-2-2022 13:19:12
 *  Author: luca1
 */ 
void lcd_strobe_lcd_e(void);
void init_4bits_mode(void);
void lcd_write_string(char *str);
void lcd_write_data(unsigned char byte);
void lcd_write_cmd(unsigned char byte);
void init();
void display_text(char *str);
void set_cursor(int position);
void clear_screen();