/*
 * RN2483.h
 *
 * Created: 14-Apr-22 16:33:26
 *  Author: Birk Tamm
 */ 


#ifndef RN2483_H_
#define RN2483_H_

void RN2483_init(void);
void RN2483_reset_band(const char* band);
void RN2483_mac_set(void);
void RN2483_join(void);


#endif /* RN2483_H_ */