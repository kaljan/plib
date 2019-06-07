/**
 * @file 	phy_lan8742a_reg.h
 * @author	kaljan
 * @version 0.0.0
 * @date 	May 7, 2019
 *
 * @brief
 */

#ifndef PHY_LAN8742A_REG_H
#define PHY_LAN8742A_REG_H

#define mBitMask(b) ((uint16_t)1) << b

#define mGetBits(reg, value, mask, offset)	\
	(uint16_t)value = (((uint16_t)reg & (((uint16_t)mask) << offset)) >> offset)

#define mSetBits(reg, value, mask, offset) \
	(uint16_t)reg = ((uint16_t)reg & (~(uint16_t)mask)) | \
	(((uint16_t)value & (uint16_t)mask) << offset)


#define PHY_LAN8742A_BCR	0	// Basic Control Register

/* Soft Reset
 *
 * 1 = Software reset. Bit is self-clearing. When setting this bit do
 * not set other bits in this register.
 *
 * Note: The configuration (as described in Section 3.7.2, "MODE[2:0]:
 *       Mode Configuration," on page 36) is set from the register bit
 *       values, and not from the mode pins.
 *
 */
#define PHY_LAN8742A_BCR_SR					mBitMask(15)

/* Loopback
 *
 * 0 = Normal operation
 * 1 = Loopback mode
 */
#define PHY_LAN8742A_BCR_LPBACK				mBitMask(14)

/* Speed Select
 *
 * 0 = 10 Mbps
 * 1 = 100 Mbps
 *
 * Note: Ignored if auto-negotiation is enabled (0.12 = 1).
 */
#define PHY_LAN8742A_BCR_SPDSEL				mBitMask(14)

/* Auto-Negotiation Enable
 *
 * 0 = Disable auto-negotiate process
 * 1 = Enable auto-negotiate process (overrides 0.13 and 0.8)
 */
#define PHY_LAN8742A_BCR_ANE				mBitMask(12)

/* Power Down
 *
 * 0 = Normal operation
 * 1 = General power down mode
 */
#define PHY_LAN8742A_BCR_PDN				mBitMask(11)

/* Restart Auto-Negotiate
 *
 * 0 = Normal operation
 * 1 = Restart auto-negotiate process
 *
 * Note: Bit is self-clearing.
 */
#define PHY_LAN8742A_BCR_RAN				mBitMask(9)

/* Duplex Mode
 *
 * 0 = Half duplex
 * 1 = Full duplex
 *
 * Note: Ignored if Auto-Negotiation is enabled (0.12 = 1).
 */
#define PHY_LAN8742A_BCR_DM					mBitMask(8)


#define PHY_LAN8742A_BSR	1	// Basic Status Register

/* 100BASE-T4
 *
 * 0 = No T4 ability
 * 1 = T4 able
 */
#define PHY_LAN8742A_BSR_100BASE_T4			mBitMask(15)

/* 100BASE-TX Full Duplex
 *
 * 0 = No TX full duplex ability
 * 1 = TX with full duplex
 */
#define PHY_LAN8742A_BSR_100BASE_TX_FD		mBitMask(14)

/* 100BASE-TX Half Duplex
 *
 * 0 = No TX half duplex ability
 * 1 = TX with half duplex
 */
#define PHY_LAN8742A_BSR_100BASE_TX_HD		mBitMask(13)

/* 10BASE-T Full Duplex
 *
 * 0 = No 10 Mbps with full duplex ability
 * 1 = 10 Mbps with full duplex
 */
#define PHY_LAN8742A_BSR_10BASE_T_FD		mBitMask(12)

/* 10BASE-T Half Duplex
 *
 * 0 = No 10 Mbps with half duplex ability
 * 1 = 10 Mbps with half duplex
 */
#define PHY_LAN8742A_BSR_BASE_T_HD			mBitMask(11)

/* 100BASE-T2 Full Duplex
 *
 * 0 = PHY is not able to perform full duplex 100BASE-T2
 * 1 = PHY is able to perform full duplex 100BASE-T2
 */
#define PHY_LAN8742A_BSR_100BASE_T2_FD		mBitMask(10)

/* 100BASE-T2 Half Duplex
 *
 * 0 = PHY is not able to perform half duplex 100BASE-T2
 * 1 = PHY is able to perform half duplex 100BASE-T2
 */
#define PHY_LAN8742A_BSR_100BASE_T2_HD		mBitMask(9)

/* Extended Status
 *
 * 0 = No extended status information in register 15
 * 1 = Extended status information in register 15
 */
#define PHY_LAN8742A_BSR_ES					mBitMask(8)

/* Auto-Negotiate Complete
 *
 * 0 = Auto-negotiate process not completed
 * 1 = Auto-negotiate process completed
 */
#define PHY_LAN8742A_BSR_ANC				mBitMask(5)

/* Remote Fault
 *
 * 1 = Remote fault condition detected
 * 0 = No remote fault
 */
#define PHY_LAN8742A_BSR_RFAULT				mBitMask(3)

/* Auto-Negotiate Ability
 *
 * 0 = Unable to perform auto-negotiation function
 * 1 = Able to perform auto-negotiation function
 */
#define PHY_LAN8742A_BSR_AN					mBitMask(4)

/* Link Status
 *
 * 0 = Link is down.
 * 1 = Link is up.
 */
#define PHY_LAN8742A_BSR_LINKSTAT			mBitMask(2)

/* Jabber Detect
 *
 * 0 = No jabber condition detected.
 * 1 = Jabber condition detected.
 */
#define PHY_LAN8742A_BSR_JABBER				mBitMask(1)

/* Extended Capabilities
 *
 * 0 = Does not support extended capabilities registers
 * 1 = Supports extended capabilities registers
 */
#define PHY_LAN8742A_BSR_EXTCAP				mBitMask(0)


#define PHY_LAN8742A_PID1	2	// PHY Identifier 1 Register
#define PHY_LAN8742A_PID2	3	// PHY Identifier 2 Register


#define PHY_LAN8742A_ANR	4	// Auto Negotiation Advertisement Register

/* Next Page
 *
 * 0 = No next page ability
 * 1 = Next page capable
 */
#define PHY_LAN8742A_ANR_NEXT_PAGE			mBitMask(15)

/* Remote Fault
 *
 * 0 = No remote fault
 * 1 = Remote fault detected
 */
#define PHY_LAN8742A_ANR_RFAULT				mBitMask(13)

/* Pause Operation
 *
 * 00 = No PAUSE
 * 01 = Symmetric PAUSE
 * 10 = Asymmetric PAUSE toward link partner
 * 11 = Advertise support for both Symmetric PAUSE and Asymmetric
 *      PAUSE toward local device
 *
 * Note: When both symmetric PAUSE and asymmetric PAUSE are set, the
 *       device will only be configured to, at most, one of the two
 *       settings upon auto-negotiation completion.
 */
#define PHY_LAN8742A_ANR_GET_PAUSE(reg, value)		mGetBits(reg, value, 3, 10)
#define PHY_LAN8742A_ANR_SET_PAUSE(reg, value)		msetBits(reg, value, 3, 10)

/* 100BASE-TX Full Duplex
 *
 * 0 = No TX full duplex ability
 * 1 = TX with full duplex
 */
#define PHY_LAN8742A_ANR_100BASE_TX_FD		mBitMask(8)

/* 100BASE-TX Full Duplex
 *
 * 0 = No TX full duplex ability
 * 1 = TX with full duplex
 */
#define PHY_LAN8742A_ANR_100BASE_TX			mBitMask(7)

/* 10BASE-T Full Duplex
 *
 * 0 = No 10 Mbps with full duplex ability
 * 1 = 10 Mbps with full duplex
 */
#define PHY_LAN8742A_ANR_10BASE_T_FD		mBitMask(6)

/* 10BASE-T
 *
 * 0 = No 10 Mbps ability
 * 1 = 10 Mbps able
 */
#define PHY_LAN8742A_ANR_10BASE_T			mBitMask(5)

/* Selector Field
 * 00001 = IEEE 802.3
 */
#define PHY_LAN8742A_ANR_GET_SEL(reg, value)		mGetBits(reg, value, 0x1F, 0)
#define PHY_LAN8742A_ANR_sET_SEL(reg, value)		mSetBits(reg, value, 0x1F, 0)


#define PHY_LAN8742A_LPAR	5	// Auto Negotiation Link Partner Ability Register

/* Next Page
 *
 * 0 = No next page ability
 * 1 = Next page capable
 */
#define PHY_LAN8742A_LPAR_NEXT_PAGE			mBitMask(15)

/* Acknowledge
 *
 * 0 = Link code word not yet received
 * 1 = Link code word received from partner
 */
#define PHY_LAN8742A_LPAR_ACK				mBitMask(14)

/* Remote Fault
 *
 * 0 = No remote fault
 * 1 = Remote fault detected
 */
#define PHY_LAN8742A_LPAR_RFAULT			mBitMask(13)

/* Pause Operation
 *
 * 00 = No PAUSE supported by partner station
 * 01 = Symmetric PAUSE supported by partner station
 * 10 = Asymmetric PAUSE supported by partner station
 * 11 = Both Symmetric PAUSE and Asymmetric PAUSE supported by
 *      partner station
 */
#define PHY_LAN8742A_LPAR_GET_PAUSE(reg, value)         mGetBits(reg, value, 0x1F, 10)
#define PHY_LAN8742A_LPAR_SET_PAUSE(reg, value)         mSetBits(reg, value, 0x1F, 10)

/* 100BASE-T4
 *
 * 0 = No T4 ability
 * 1 = T4 able
 *
 * Note: This device does not support T4 ability.
 */
#define PHY_LAN8742A_LPAR_100BASE_T4		mBitMask(9)

/* 100BASE-TX Full Duplex
 *
 * 0 = No TX full duplex ability
 * 1 = TX with full duplex
 */
#define PHY_LAN8742A_LPAR_100BASE_TX_FD		mBitMask(8)

/* 100BASE-TX
 *
 * 0 = No TX ability
 * 1 = TX able
 */
#define PHY_LAN8742A_LPAR_100BASE_TX		mBitMask(7)

/* 10BASE-T Full Duplex
 *
 * 0 = No 10 Mbps with full duplex ability
 * 1 = 10 Mbps with full duplex
 */
#define PHY_LAN8742A_LPAR_10BASE_T_FD		mBitMask(6)

/* 10BASE-T
 *
 * 0 = No 10 Mbps ability
 * 1 = 10 Mbps able
 */
#define PHY_LAN8742A_LPAR_10BASE_T			mBitMask(5)

/* Selector Field
 * 00001 = IEEE 802.3
 */
#define PHY_LAN8742A_LPAR_GET_SEL(reg, value)		mGetBits(reg, value, 0x1F, 0)


#define PHY_LAN8742A_ER		6	// Auto Negotiation Expansion Register

/* Receive Next Page Location Able
 *
 * 0 = Received next page storage location is not specified by bit 6.5
 * 1 = Received next page storage location is specified by bit 6.5
 */
#define PHY_LAN8742A_ER_RNPLA				mBitMask(6)

/* Received Next Page Storage Location
 *
 * 0 = Link partner next pages are stored in the Auto Negotiation
 *     Link Partner Ability Register (PHY register 5)
 * 1 = Link partner next pages are stored in the Auto Negotiation
 *     Next Page RX Register (PHY register 8)
 */
#define PHY_LAN8742A_ER_RNPSL				mBitMask(5)

/* Parallel Detection Fault
 *
 * 0 = No fault detected by parallel detection logic .
 * 1 = Fault detected by parallel detection logic
 */
#define PHY_LAN8742A_ER_PDFAULT				mBitMask(4)

/* Link Partner Next Page Able
 *
 * 0 = Link partner does not have next page ability.
 * 1 = Link partner has next page ability.
 */
#define PHY_LAN8742A_ER_LPNPA				mBitMask(3)

/* Next Page Able
 *
 * 0 = Local device does not have next page ability. .
 * 1 = Local device has next page ability.
 */
#define PHY_LAN8742A_ER_NPA					mBitMask(2)

/* Page Received
 *
 * 0 = New page not yet received
 * 1 = New page received
 */
#define PHY_LAN8742A_ER_PRECVD				mBitMask(1)

/* Link Partner Auto-Negotiation Able
 *
 * 0 = Link partner does not have auto-negotiation ability.
 * 1 = Link partner has auto-negotiation ability.
 */
#define PHY_LAN8742A_ER_LPANA				mBitMask(0)



#define PHY_LAN8742A_NPTXR	7	// Auto Negotiation Next Page TX Register

/* Next Page
 *
 * 0 = No next page ability
 * 1 = Next page capable
 */
#define PHY_LAN8742A_NPTXR_NEXT_PAGE		mBitMask(15)

/* Message Page
 *
 * 0 = Unformatted page
 * 1 = Message page
 */
#define PHY_LAN8742A_NPTXR_MSG_PAGE			mBitMask(13)

/* Acknowledge 2
 *
 * 0 = Device cannot comply with message.
 * 1 = Device will comply with message.
 */
#define PHY_LAN8742A_NPTXR_ACK2				mBitMask(12)

/* Toggle
 *
 * 0 = Previous value was HIGH.
 * 1 = Previous value was LOW.
 */
#define PHY_LAN8742A_NPTXR_TOGGLE			mBitMask(11)

/* Message Code
 * Message/Unformatted Code Field
 */
#define PHY_LAN8742A_NPTXR_GET_MSG_CODE(reg, value)		mGetBits(reg, value, 0x03FF, 0)
#define PHY_LAN8742A_NPTXR_SET_MSG_CODE(reg, value)		mSetBits(reg, value, 0x03FF, 0)


#define PHY_LAN8742A_NPRXR	8	// Auto Negotiation Next Page RX Register

/* Next Page
 *
 * 0 = No next page ability
 * 1 = Next page capable
 */
#define PHY_LAN8742A_NPRXR_NEXT_PAGE		mBitMask(15)

/* Acknowledge
 *
 * 0 = Link code word not yet received from partner
 * 1 = Link code word received from partner
 */
#define PHY_LAN8742A_NPRXR_ACK				mBitMask(14)

/* Message Page
 *
 * 0 = Unformatted page
 * 1 = Message page
 */
#define PHY_LAN8742A_NPRXR_MSG_PAGE			mBitMask(13)

/* Acknowledge 2
 *
 * 0 = Device cannot comply with message.
 * 1 = Device will comply with message.
 */
#define PHY_LAN8742A_NPRXR_ACK2				mBitMask(12)

/* Toggle
 *
 * 0 = Previous value was HIGH.
 * 1 = Previous value was LOW.
 */
#define PHY_LAN8742A_NPRXR_TOGGLE			mBitMask(11)

/* Message Code
 * Message/Unformatted Code Field
 */
#define PHY_LAN8742A_NPRXR_GET_MSG_CODE(reg, value)		mGetBits(reg, value, 0x03FF, 0)
#define PHY_LAN8742A_NPRXR_SET_MSG_CODE(reg, value)		mSetBits(reg, value, 0x03FF, 0)


#define PHY_LAN8742A_MMDACR	13	// MMD Access Control Register

/* MMD Function This field is used to select the desired MMD function:
 *
 * 00 = Address
 * 01 = Data, no post increment
 * 10 = RESERVED
 * 11 = RESERVED
 */
#define PHY_LAN8742A_MMDACR_GET_MMDFN(reg, value)		mGetBits(reg, value, 3, 14)
#define PHY_LAN8742A_MMDACR_SET_MMDFN(reg, value)		mSetBits(reg, value, 3, 14)

/* MMD Device Address (DEVAD)
 * This field is used to select the desired MMD device address.
 * (3 = PCS)
 */
#define PHY_LAN8742A_MMDACR_GET_MMD_DEV_ADDR(reg, value)		mGetBits(reg, value, 0x001F, 0)
#define PHY_LAN8742A_MMDACR_SET_MMD_DEV_ADDR(reg, value)		mSetBits(reg, value, 0x001F, 0)

#define PHY_LAN8742A_MMDDR	14	// MMD Access Address/Data Register

#define PHY_LAN8742A_EDPD_CTR	16	// EDPD NLP / Crossover Time Register

/* EDPD TX NLP Enable
 * When in Energy Detect Power-Down (EDPD) mode (EDPWRDOWN = 1), this
 * bit enables the transmission of single TX NLPs at the interval
 * defined by the EDPD TX NLP Interval Timer Select field.
 *
 * 0 = TX NLP disabled
 * 1 = TX NLP enabled when in EDPD mode
 */
#define PHY_LAN8742A_EDPD_CTR_TX_NLP_EN		mBitMask(15)

/* EDPD TX NLP Interval Timer Select
 * When in Energy Detect Power-Down (EDPD) mode (EDPWRDOWN = 1) and
 * EDPD TX NLP Enable is 1, this field defines the interval used to
 * send single TX NLPs.
 *
 * 00 = 1 second (default)
 * 01 = 768 ms
 * 10 = 512 ms
 * 11 = 256 ms
 */
#define PHY_LAN8742A_EDPD_CTR_GET_TX_NLP_ITS(reg, value)	mGetBits(reg, value, 0x03, 13)
#define PHY_LAN8742A_EDPD_CTR_SET_TX_NLP_ITS(reg, value)	mSetBits(reg, value, 0x03, 13)

/* EDPD RX Single NLP Wake Enable
 * When in Energy Detect Power-Down (EDPD) mode (EDPWRDOWN = 1), this
 * bit enables waking the PHY on reception of a single RX NLP.
 *
 * 0 = RX NLP wake disabled
 * 1 = TX NLP wake enabled when in EDPD mode
 */
#define PHY_LAN8742A_EDPD_CTR_RX_NLP_EN		mBitMask(12)

/* EDPD RX NLP Max Interval Detect Select
 * When in Energy Detect Power-Down (EDPD) mode (EDPWRDOWN = 1) and
 * EDPD RX Single NLP Wake Enable is 0, this field defines the
 * maximum interval for detecting two RX NLPs to wake from EDPD
 * mode
 *
 * 00 = 64 ms (default)
 * 01 = 256 ms
 * 10 = 512 ms
 * 11 = 1 second
 */
#define PHY_LAN8742A_EDPD_CTR_GET_RX_INT(reg, value)	mGetBits(reg, value, 0x03, 10)
#define PHY_LAN8742A_EDPD_CTR_SET_RX_INT(reg, value)	mSetBits(reg, value, 0x03, 10)

/* EDPD Extend Crossover
 * When in Energy Detect Power-Down (EDPD) mode (EDPWRDOWN = 1),
 * setting this bit to 1 extends the crossover time by 2976 ms.
 * 0 = Crossover time extension disabled
 * 1 = Crossover time extension enabled (2976 ms)
 */
#define PHY_LAN8742A_EDPD_CTR_EC			mBitMask(1)

/* Extend Manual 10/100 Auto-MDIX Crossover Time
 * When Auto-MIDX is enabled and the PHY is in manual 10BASE-T or
 * 100BASE-TX mode, setting this bit to 1 extends the crossover time
 * by 1984 ms to allow linking to an auto-negotiation link partner PHY.
 *
 * 0 = Crossover time extension disabled
 * 1 = Crossover time extension enabled (1984 ms)
 */
#define PHY_LAN8742A_EDPD_CTR_EM			mBitMask(0)


#define PHY_LAN8742A_MCSR	17	// Mode Control/Status Register

/* EDPWRDOWN
 * Enable the Energy Detect Power-Down (EDPD) mode:
 *
 * 0 = Energy Detect Power-Down is disabled.
 * 1 = Energy Detect Power-Down is enabled.
 *
 * Note: When in EDPD mode, the device’s NLP characteristics can be
 *       modified via the EDPD NLP / Crossover Time Register.
 */
#define PHY_LAN8742A_MCSR_EDPWRDOWN			mBitMask(13)

/* FARLOOPBACK
 * Enables far loopback mode (i.e., all the received packets are sent
 * back simultaneously (in 100BASE-TX only)). This mode works even if
 * the Isolate bit (0.10) is set.
 *
 * 0 = Far loopback mode is disabled.
 * 1 = Far loopback mode is enabled.
 *
 * Refer to Section 3.8.10.2, "Far Loopback," on page 58 for
 * additional information.
 */
#define PHY_LAN8742A_MCSR_FARLOOPBACK		mBitMask(9)

/* ALTINT
 * Alternate Interrupt Mode:
 *
 * 0 = Primary interrupt system enabled (Default)
 * 1 = Alternate interrupt system enabled
 *
 * Refer to Section 3.6, "Interrupt Management," on page 32 for additional information.
 */
#define PHY_LAN8742A_MCSR_ALTINT			mBitMask(6)

/* ENERGYON
 * Indicates whether energy is detected. This bit transitions to “0”
 * if no valid energy is detected within 256 ms. It is reset to “1”
 * by a hardware reset and is unaffected by a software reset. Refer
 * to Section 3.8.3.2, "Energy Detect Power-Down (EDPD)," on page 47
 * for additional information.
 */
#define PHY_LAN8742A_MCSR_ENERGYON			mBitMask(1)


#define PHY_LAN8742A_SMR	18	// Special Modes Register

/* MODE
 * Transceiver mode of operation. Refer to Section 3.7.2, "MODE[2:0]:
 * Mode Configuration," on page 36 for additional details.
 */
#define PHY_LAN8742A_SMR_GET_MODE(reg, value)		mGetBits(reg, value, 0x07, 5)
#define PHY_LAN8742A_SMR_SET_MODE(reg, value)		mSetBits(reg, value, 0x07, 5)

/* PHYAD
 * PHY Address. The PHY Address is used for the SMI address and for
 * initialization of the Cipher (Scrambler) key. Refer to Section
 * 3.7.1, "PHYAD[0]: PHY Address Configuration," on page 35 for
 * additional details.
 */
#define PHY_LAN8742A_SMR_GET_PHYAD(reg, value)		mGetBits(reg, value, 0x001F, 0)
#define PHY_LAN8742A_SMR_SET_PHYAD(reg, value)		mSetBits(reg, value, 0x001F, 0)

#define PHY_LAN8742A_TDR	24	// TDR Patterns/Delay Control Register

/* TDR Delay In
 *
 * 0 = Line break time is 2 ms.
 * 1 = The device uses TDR Line Break Counter to increase the line
 *     break time before starting TDR.
 */
#define PHY_LAN8742A_TDR_DELAY				mBitMask(15)

/* TDR Line Break Counter
 * When TDR Delay In is 1, this field specifies the increase in line
 * break time in increments of 256 ms, up to 2 seconds.
 */
#define PHY_LAN8742A_TDR_GET_LBC(reg, value)		mGetBits(reg, value, 0x07, 12)
#define PHY_LAN8742A_TDR_SET_LBC(reg, value)		mSetBits(reg, value, 0x007, 12)

/* TDR Pattern High
 * This field specifies the data pattern sent in TDR mode for the
 * high cycle.
 */
#define PHY_LAN8742A_TDR_GET_PH(reg, value)		mGetBits(reg, value, 0x003F, 6)
#define PHY_LAN8742A_TDR_SET_PH(reg, value)		mSetBits(reg, value, 0x003F, 6)

/* TDR Pattern Low
 * This field specifies the data pattern sent in TDR mode for the
 * low cycle.
 */
#define PHY_LAN8742A_TDR_GET_PL(reg, value)		mGetBits(reg, value, 0x003F, 0)
#define PHY_LAN8742A_TDR_SET_PL(reg, value)		mSetBits(reg, value, 0x003F, 0)

#define PHY_LAN8742A_TDR_CSR	25	// TDR Control/Status Register

/* TDR Enable
 *
 * 0 = TDR mode disabled
 * 1 = TDR mode enabled
 *
 * Note: This bit self clears when TDR completes (TDR Channel Status
 *       goes high)
 */
#define PHY_LAN8742A_TDR_CSR_EN				mBitMask(15)

/* TDR Analog to Digital Filter Enable
 *
 * 0 = TDR analog to digital filter disabled
 * 1 = TDR analog to digital filter enabled (reduces noise spikes
 *     during TDR pulses)
 */
#define PHY_LAN8742A_TDR_CSR_ADFILT_EN		mBitMask(14)

/* TDR Channel Cable Type
 * Indicates the cable type determined by the TDR test.
 *
 * 00 = Default
 * 01 = Shorted cable condition
 * 10 = Open cable condition
 * 11 = Match cable condition
 */
#define PHY_LAN8742A_TDR_CSR_GET_CC_TYPE(reg, value)		mGetBits(reg, value, 3, 9)
#define PHY_LAN8742A_TDR_CSR_SET_CC_TYPE(reg, value)		mSetBits(reg, value, 3, 9)

/* TDR Channel Status
 * When high, this bit indicates that the TDR operation has
 * completed. This bit will stay high until reset or the TDR
 * operation is restarted (TDR Enable = 1)
 */
#define PHY_LAN8742A_TDR_CSR_CHST			mBitMask(8)

/* TDR Channel Length
 * This eight bit value indicates the TDR channel length during a
 * short or open cable condition. Refer to Section 3.8.9.1, "Time
 * Domain Reflectometry (TDR) Cable Diagnostics," on page 54 for
 * additional information on the usage of this field.
 *
 * Note: This field is not valid during a match cable condition. The
 *       Cable Length Register must be used to determine cable length
 *       during a non-open/short (match) condition. Refer to Section
 *       3.8.9, "Cable Diagnostics," on page 53 for additional
 *       information.
 */
#define PHY_LAN8742A_TDR_CSR_GET_CHLEN(reg, value)		mGetBits(reg, value, 0x00FF, 0)
#define PHY_LAN8742A_TDR_CSR_SET_CHLEN(reg, value)		mSetBits(reg, value, 0x00FF, 0)


#define PHY_LAN8742A_SECR	26	// Symbol Error Counter Register


#define PHY_LAN8742A_SCSIR	27	// Special Control/Status Indications Register

/* AMDIXCTRL
 * HP Auto-MDIX control:
 *
 * 0 = Enable Auto-MDIX
 * 1 = Disable Auto-MDIX (use 27.13 to control channel)
 */
#define PHY_LAN8742A_SCSIR_AMDIXCTRL		mBitMask(15)

/* CH_SELECT
 * Manual channel select:
 *
 * 0 = MDI (TX transmits, RX receives)
 * 1 = MDIX (TX receives, RX transmits)
 */
#define PHY_LAN8742A_SCSIR_CH_SELECT		mBitMask(13)

/* SQEOFF
 * Disable the SQE test (Heartbeat):
 *
 * 0 = SQE test is enabled
 * 1 = SQE test is disabled
 */
#define PHY_LAN8742A_SCSIR_SQEOFF			mBitMask(11)

/* XPOL
 * Polarity state of the 10BASE-T:
 *
 * 0 = Normal polarity
 * 1 = Reversed polarity
 */
#define PHY_LAN8742A_SCSIR_XPOL				mBitMask(4)


#define PHY_LAN8742A_CLR	28	// Cable Length Register

/* Cable Length (CBLN)
 * This four bit value indicates the cable length. Refer to Section
 * 3.8.9.2, "Matched Cable Diagnostics," on page 57 for additional
 * information on the usage of this field.
 *
 * Note: This field indicates cable length for 100BASE-TX linked
 *       devices that do not have an open/short on the cable. To
 *       determine the open/short status of the cable, the TDR
 *       Patterns/Delay Control Register and TDR Control/Status
 *       Register must be used. Cable length is not supported for
 *       10BASE-T links. Refer to Section 3.8.9, "Cable Diagnostics,"
 *       on page 53 for additional information.
 */
#define PHY_LAN8742A_CLR_CBLN(reg, value)		mGetBits(reg, value, 0x0F, 12)

#define PHY_LAN8742A_ISFR	29	// Interrupt Source Flag Register

/* INT8
 * 0 = Not source of interrupt
 * 1 = Wake on LAN (WoL) event detected
 */
#define PHY_LAN8742A_ISFR_INT8				mBitMask(8)

/* INT7
 * 0 = Not source of interrupt
 * 1 = ENERGYON generated
 */
#define PHY_LAN8742A_ISFR_INT7				mBitMask(7)

/* INT6
 * 0 = Not source of interrupt
 * 1 = Auto-Negotiation complete
 */
#define PHY_LAN8742A_ISFR_INT6				mBitMask(6)

/* INT5
 * 0 = Not source of interrupt
 * 1 = Remote Fault Detected
 */
#define PHY_LAN8742A_ISFR_INT5				mBitMask(5)

/* INT4
 * 0 = Not source of interrupt
 * 1 = Link Down (link status negated)
 */
#define PHY_LAN8742A_ISFR_INT4				mBitMask(4)

/* INT3
 * 0 = Not source of interrupt
 * 1 = Auto-Negotiation LP Acknowledge
 */
#define PHY_LAN8742A_ISFR_INT3				mBitMask(3)

/* INT2
 * 0 = Not source of interrupt
 * 1 = Parallel Detection Fault
 */
#define PHY_LAN8742A_ISFR_INT2				mBitMask(2)

/* INT1
 * 0 = Not source of interrupt
 * 1 = Auto-Negotiation Page Received
 */
#define PHY_LAN8742A_ISFR_INT1				mBitMask(1)


#define PHY_LAN8742A_IMR	30	// Interrupt Mask Register

/* INT8
 * 0 = Not source of interrupt
 * 1 = Wake on LAN (WoL) event detected
 */
#define PHY_LAN8742A_IMR_INT8				mBitMask(8)

/* INT7
 * 0 = Not source of interrupt
 * 1 = ENERGYON generated
 */
#define PHY_LAN8742A_IMR_INT7				mBitMask(7)

/* INT6
 * 0 = Not source of interrupt
 * 1 = Auto-Negotiation complete
 */
#define PHY_LAN8742A_IMR_INT6				mBitMask(6)

/* INT5
 * 0 = Not source of interrupt
 * 1 = Remote Fault Detected
 */
#define PHY_LAN8742A_IMR_INT5				mBitMask(5)

/* INT4
 * 0 = Not source of interrupt
 * 1 = Link Down (link status negated)
 */
#define PHY_LAN8742A_IMR_INT4				mBitMask(4)

/* INT3
 * 0 = Not source of interrupt
 * 1 = Auto-Negotiation LP Acknowledge
 */
#define PHY_LAN8742A_IMR_INT3				mBitMask(3)

/* INT2
 * 0 = Not source of interrupt
 * 1 = Parallel Detection Fault
 */
#define PHY_LAN8742A_IMR_INT2				mBitMask(2)

/* INT1
 * 0 = Not source of interrupt
 * 1 = Auto-Negotiation Page Received
 */
#define PHY_LAN8742A_IMR_INT1				mBitMask(1)


/* Mask Bits
 * These bits mask the corresponding interrupts in the Interrupt
 * Source Flag Register.
 *
 * 0 = Interrupt source is masked.
 * 1 = Interrupt source is enabled.
 */
#define PHY_LAN8742A_IMR_GET_MASK(reg, value)		mGetBits(reg, value, 0x001F, 0)
#define PHY_LAN8742A_IMR_SET_MASK(reg, value)		mSetBits(reg, value, 0x001F, 0)

#define PHY_LAN8742A_SCSR	31	// PHY Special Control/Status Register

/* Autodone
 * Auto-negotiation done indication:
 *
 * 0 = Auto-negotiation is not done or disabled (or not active).
 * 1 = Auto-negotiation is done.
 */
#define PHY_LAN8742A_SCSR_AUTODONE			mBitMask(12)

/* Speed Indication
 * HCDSPEED value:
 *
 * 001 = 10BASE-T half-duplex
 * 101 = 10BASE-T full-duplex
 * 010 = 100BASE-TX half-duplex
 * 110 = 100BASE-TX full-duplex
 */
#define PHY_LAN8742A_SCSR_GET_HCDSPD(reg, value)		mGetBits(reg, value, 7, 2)

#endif // PHY_LAN8742A_REG_H
