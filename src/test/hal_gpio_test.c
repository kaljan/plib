

//	hal_gpio_add_di(45, pc13_callback);

//
//	hal_gpio_init(23, OUTPUT);

//	hal_gpio_init(30, OUTPUT);
//		hal_gpio_di_poll();
//int i = 0;
//_Bool led2_state = false;
//_Bool led3_state = false;
//
//void pc13_callback(event_t event) {
//	if (event == RISING) {
//		switch(i) {
//		case 0:
//			led2_state = false;
//			led3_state = false;
//			break;
//		case 1:
//			led2_state = true;
//			led3_state = false;
//			break;
//		case 2:
//			led2_state = true;
//			led3_state = true;
//			break;
//		case 3:
//			led2_state = false;
//			led3_state = true;
//			break;
//		default:
//			break;
//		}
//
//		hal_gpio_set_value(23, led2_state);
//		hal_gpio_set_value(30, led3_state);
//		i++;
//		if (i > 3) {
//			i = 0;
//		}
//	}
//}

//		if (release == TRUE) {
//			release = FALSE;
//			press = FALSE;
//		}

//		value = hal_gpio_get_debounce_value(45);
//		if (value != prev_value) {
//			prev_value = value;
//			if (press == FALSE) {
//				press = TRUE;
//				continue;
//			}
//			if (release == FALSE) {
//				release = TRUE;
//			}
//		}
//		if (value == LOW) {
//			value = HIGH;
//		} else {
//			value = LOW;
//		}
//		hal_gpio_set_value(23, value);
