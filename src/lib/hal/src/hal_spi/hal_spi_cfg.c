#include "hal_spi_cfg.h"


void hal_spi_set_bidirect_mode(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_BIDIMODE;
		} else {
			spi->CR1 &= ~SPI_CR1_BIDIMODE;
		}
	}
}

void hal_spi_set_direction(SPI_TypeDef * spi, direction_t direction) {
	if (spi && (spi->CR1 & SPI_CR1_BIDIMODE)) {
		if (direction == OUTPUT) {
			spi->CR1 |= SPI_CR1_BIDIOE;
		} else {
			spi->CR1 &= ~SPI_CR1_BIDIOE;
		}
	}
}

void hal_spi_set_rx_only(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_RXONLY;
		} else {
			spi->CR1 &= ~SPI_CR1_RXONLY;
		}
	}
}

void hal_spi_set_ssm(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_SSM;
		} else {
			spi->CR1 &= ~SPI_CR1_SSM;
		}
	}
}

void hal_spi_set_ssi(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_SSI;
		} else {
			spi->CR1 &= ~SPI_CR1_SSI;
		}
	}
}

void hal_spi_set_lsb_first(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_LSBFIRST;
		} else {
			spi->CR1 &= ~SPI_CR1_LSBFIRST;
		}
	}
}

void hal_spi_enable(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_SPE;
		} else {
			spi->CR1 &= ~SPI_CR1_SPE;
		}
	}
}

void hal_spi_set_baud(SPI_TypeDef * spi, hal_spi_baudrate_t baudrate) {
	if (spi) {
		spi->CR1 &= ~SPI_CR1_BR_Msk;
		spi->CR1 |= ((baudrate & 0x7) << SPI_CR1_BR_Pos);
	}
}

void hal_spi_set_master(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_MSTR;
		} else {
			spi->CR1 &= ~SPI_CR1_MSTR;
		}
	}
}

void hal_spi_set_cpol(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_CPOL;
		} else {
			spi->CR1 &= ~SPI_CR1_CPOL;
		}
	}
}

void hal_spi_set_cpha(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR1 |= SPI_CR1_CPHA;
		} else {
			spi->CR1 &= ~SPI_CR1_CPHA;
		}
	}
}

void hal_spi_set_data_size(SPI_TypeDef * spi, hal_spi_data_size_t size) {
	if (spi) {
		spi->CR2 &= ~SPI_CR2_DS_Msk;
		spi->CR2 |= ((size & 0x7) << SPI_CR2_DS_Pos);
	}
}

void hal_spi_txe_irq_enable(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR2 |= SPI_CR2_TXEIE;
		} else {
			spi->CR2 &= ~SPI_CR2_TXEIE;
		}
	}
}

void hal_spi_rxne_irq_enable(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR2 |= SPI_CR2_RXNEIE;
		} else {
			spi->CR2 &= ~SPI_CR2_RXNEIE;
		}
	}
}

void hal_spi_err_irq_enable(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR2 |= SPI_CR2_ERRIE;
		} else {
			spi->CR2 &= ~SPI_CR2_ERRIE;
		}
	}
}

void hal_spi_tx_dma_enable(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR2 |= SPI_CR2_TXDMAEN;
		} else {
			spi->CR2 &= ~SPI_CR2_TXDMAEN;
		}
	}
}

void hal_spi_rx_dma_enable(SPI_TypeDef * spi, _Bool enabled) {
	if (spi) {
		if (enabled) {
			spi->CR2 |= SPI_CR2_RXDMAEN;
		} else {
			spi->CR2 &= ~SPI_CR2_RXDMAEN;
		}
	}
}

_Bool hal_spi_set_config(SPI_TypeDef * context, hal_spi_cfg_t * config) {
	if (context && config) {
		hal_spi_set_cpol(context, config->cpol);
		hal_spi_set_cpha(context, config->cpha);
		hal_spi_set_lsb_first(context, config->lsb_first);
		hal_spi_set_data_size(context, config->datasize);
		hal_spi_set_baud(context, config->baudrate);
		hal_spi_set_ssm(context, config->soft_slave_mgmt);
		hal_spi_set_ssi(context, config->internal_slave_select);
		hal_spi_set_master(context, config->master);
		hal_spi_enable(context, true);
		return true;
	}
	return false;
}

