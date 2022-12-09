# maag library component. Add c/cpp files here, also add required idf-components!

idf_component_register(SRCS 	"maag_gpio.cpp"
                            	"maag_i2c_device.cpp"
				"maag_i2c_port.cpp" 
                            	"maag_sntp.cpp" 
                            	"maag_spi_device.cpp"
			    	"maag_spi_host.cpp"
                          	"maag_webserver.cpp"
				"maag_wifi.cpp"
                            	PRIV_REQUIRES driver nvs_flash nghttp lwip
                            	INCLUDE_DIRS "." "./include")