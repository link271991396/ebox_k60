/**
 * @file HW_FLASH.h
 * @version 3.0[By LPLD]
 * @date 2013-06-18
 * @brief FTFL�ײ�ģ����غ���
 *
 * ���Ľ���:�������޸�
 *
 * ��Ȩ����:�����������µ��Ӽ������޹�˾
 * http://www.lpld.cn
 * mail:support@lpld.cn
 *
 * @par
 * ����������������[LPLD]������ά������������ʹ���߿���Դ���롣
 * �����߿���������ʹ�û��Դ���롣�����μ�����ע��Ӧ���Ա�����
 * ���ø��Ļ�ɾ��ԭ��Ȩ���������������ο����߿��Լ�ע���ΰ�Ȩ�����ߡ�
 * ��Ӧ�����ش�Э��Ļ����ϣ�����Դ���롢���ó��۴��뱾����
 * �������²���������ʹ�ñ��������������κ��¹ʡ��������λ���ز���Ӱ�졣
 * ����������������͡�˵��������ľ���ԭ�������ܡ�ʵ�ַ�����
 * ������������[LPLD]��Ȩ�������߲��ý�������������ҵ��Ʒ��
 */
#ifndef _HW_FLASH_H_
#define _HW_FLASH_H_
/********************************************************************/
#include "../ebox/ebox_common.h"
#define CPU_MK60DZ10 //to do 

/* ������붨�� */
#define FLASH_OK                    0x00
#define FLASH_FACCERR               0x01
#define FLASH_FPVIOL                0x02
#define FLASH_MGSTAT0               0x04
#define FLASH_RDCOLERR              0x08
#define FLASH_NOT_ERASED            0x10
#define FLASH_CONTENTERR            0x11

#if defined(CPU_MK60DZ10) || defined(CPU_MK60D10) 
/* flash���� */
#define FLASH_CMD_PGM4              0x06      //��̳�������
#define FLASH_CMD_ERSSCR            0x09      //����Flash��������
#define BYTE_DIV    (4)
#elif defined(CPU_MK60F12) || defined(CPU_MK60F15)
/* flash���� */
#define FlashCmd_ProgramPhrase      0x07
#define FlashCmd_SectorErase        0x09
#define FlashCmd_ProgramSection     0x0B
#define BYTE_DIV    (8)
#endif
class FLASHCLASS
{
private:
void flash_init(void);
uint8_t flash_sector_erase(uint32_t);
uint8_t flash_byte_program(uint32_t, uint32_t*, uint32_t);
};
#endif /*_HW_FLASH_H_*/
