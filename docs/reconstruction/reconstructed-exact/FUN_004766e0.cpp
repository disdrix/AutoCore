// =============================================================================
// FUN_004766e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004766e0
// Address:   0x004766e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004766e0 @ 0x004766e0
// Stable ID: aa_004766e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~267 non-empty decompiler lines.
//  - Control keywords: if×62, do×5, while×5, return×3, goto×1.
//  - Notable callees: free×17, FUN_004766e0×4, FUN_00477710.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_004766e0(int param_1,int param_2,uint param_3,int param_4)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  

  if (param_1 == 0) {

    return;

  }

  if (param_2 == 0) {

    return;

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x4000) != 0) {

    if (param_4 == -1) {

      iVar3 = 0;

      if (0 < *(int *)(param_2 + 0x30)) {

        do {

          FUN_004766e0(param_1,param_2,0x4000,iVar3);

          iVar3 = iVar3 + 1;

        } while (iVar3 < *(int *)(param_2 + 0x30));

      }

      if (*(void **)(param_2 + 0x38) != (void *)0x0) {

        if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

          free(*(void **)(param_2 + 0x38));

        }

        else {

          (**(code **)(param_1 + 0x24c))(param_1);

        }

      }

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = 0;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = 0;

    }

    else if ((*(int *)(param_2 + 0x38) != 0) &&

            (*(int *)(*(int *)(param_2 + 0x38) + 4 + param_4 * 0x10) != 0)) {

      FUN_00477710();

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x38) + 4 + param_4 * 0x10) = 0;

    }

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x2000) != 0) {

    if (*(void **)(param_2 + 0x4c) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 0x4c));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffffef;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c) = 0;

  }

  uVar2 = *(uint *)(param_2 + 0xb8) & param_3;

  if ((uVar2 & 0x100) != 0) {

    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0xbf;

  }

  if ((char)uVar2 < '\0') {

    if (*(void **)(param_2 + 0xa0) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 0xa0));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    if (*(void **)(param_2 + 0xac) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 0xac));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xa0) = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xac) = 0;

    if (*(int *)(param_2 + 0xb0) != 0) {

      iVar3 = 0;

      if (*(char *)(param_2 + 0xb5) != '\0') {

        do {

          pvVar1 = *(void **)(*(int *)(param_2 + 0xb0) + iVar3 * 4);

          if (pvVar1 != (void *)0x0) {

            if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

              free(pvVar1);

            }

            else {

              (**(code **)(param_1 + 0x24c))(param_1);

            }

          }

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xb0) + iVar3 * 4) = 0;

          iVar3 = iVar3 + 1;

        } while (iVar3 < (int)(uint)*(byte *)(param_2 + 0xb5));

      }

      if (*(void **)(param_2 + 0xb0) != (void *)0x0) {

        if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

          free(*(void **)(param_2 + 0xb0));

        }

        else {

          (**(code **)(param_1 + 0x24c))(param_1);

        }

      }

      *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0) = 0;

    }

    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0xfb;

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x10) != 0) {

    if (*(void **)(param_2 + 0xc4) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 0xc4));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    if (*(void **)(param_2 + 200) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 200));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0xef;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 200) = 0;

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x20) != 0) {

    if (param_4 == -1) {

      if (*(int *)(param_2 + 0xd8) != 0) {

        iVar3 = 0;

        if (0 < *(int *)(param_2 + 0xd8)) {

          do {

            FUN_004766e0(param_1,param_2,0x20,iVar3);

            iVar3 = iVar3 + 1;

          } while (iVar3 < *(int *)(param_2 + 0xd8));

        }

        if (*(void **)(param_2 + 0xd4) != (void *)0x0) {

          if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

            free(*(void **)(param_2 + 0xd4));

          }

          else {

            (**(code **)(param_1 + 0x24c))(param_1);

          }

        }

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xd4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8) = 0;

      }

      *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0xdf;

    }

    else if (*(int *)(param_2 + 0xd4) != 0) {

      iVar3 = param_4 * 0x10;

      pvVar1 = *(void **)(*(int *)(param_2 + 0xd4) + iVar3);

      if (pvVar1 != (void *)0x0) {

        if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

          free(pvVar1);

        }

        else {

          (**(code **)(param_1 + 0x24c))(param_1);

        }

      }

      pvVar1 = *(void **)(*(int *)(param_2 + 0xd4) + 8 + iVar3);

      if (pvVar1 != (void *)0x0) {

        if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

          free(pvVar1);

        }

        else {

          (**(code **)(param_1 + 0x24c))(param_1);

        }

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xd4) + iVar3) = 0;

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xd4) + 8 + iVar3) = 0;

    }

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x200) != 0) {

    if (param_4 == -1) {

      if (*(int *)(param_2 + 0xc0) != 0) {

        iVar3 = 0;

        if (0 < *(int *)(param_2 + 0xc0)) {

          do {

            FUN_004766e0(param_1,param_2,0x200,iVar3);

            iVar3 = iVar3 + 1;

          } while (iVar3 < *(int *)(param_2 + 0xc0));

        }

        if (*(void **)(param_2 + 0xbc) != (void *)0x0) {

          if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

            free(*(void **)(param_2 + 0xbc));

          }

          else {

            (**(code **)(param_1 + 0x24c))(param_1);

          }

        }

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc) = 0;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xc0) = 0;

      }

    }

    else if (*(int *)(param_2 + 0xbc) != 0) {

      iVar3 = param_4 * 0x14;

      pvVar1 = *(void **)(*(int *)(param_2 + 0xbc) + 8 + iVar3);

      if (pvVar1 != (void *)0x0) {

        if (*(code **)(param_1 + 0x24c) != (code *)0x0) {

          (**(code **)(param_1 + 0x24c))(param_1);

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xbc) + 8 + iVar3) = 0;

          goto LAB_00476add;

        }

        free(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xbc) + 8 + iVar3) = 0;

    }

  }

LAB_00476add:

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 8) != 0) {

    if (*(void **)(param_2 + 0x7c) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 0x7c));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffffbf;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c) = 0;

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x1000) != 0) {

    if (*(void **)(param_2 + 0x10) != (void *)0x0) {

      if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

        free(*(void **)(param_2 + 0x10));

      }

      else {

        (**(code **)(param_1 + 0x24c))(param_1);

      }

    }

    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffff7;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = 0;

    *(uint16_t *)(param_2 + 0x14) = 0;

  }

  if ((*(uint *)(param_2 + 0xb8) & param_3 & 0x40) != 0) {

    if (*(int *)(param_2 + 0xf8) != 0) {

      iVar3 = 0;

      if (0 < *(int *)(param_2 + 4)) {

        do {

          pvVar1 = *(void **)(*(int *)(param_2 + 0xf8) + iVar3 * 4);

          if (pvVar1 != (void *)0x0) {

            if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

              free(pvVar1);

            }

            else {

              (**(code **)(param_1 + 0x24c))(param_1);

            }

          }

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xf8) + iVar3 * 4) = 0;

          iVar3 = iVar3 + 1;

        } while (iVar3 < *(int *)(param_2 + 4));

      }

      if (*(void **)(param_2 + 0xf8) != (void *)0x0) {

        if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

          free(*(void **)(param_2 + 0xf8));

        }

        else {

          (**(code **)(param_1 + 0x24c))(param_1);

        }

      }

      *(uint32_t /* width from decompiler */ *)(param_2 + 0xf8) = 0;

    }

    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0x7f;

  }

  if (param_4 != -1) {

    param_3 = param_3 & 0xffffbddf;

  }

  *(uint *)(param_2 + 0xb8) = *(uint *)(param_2 + 0xb8) & ~param_3;

  return;

}
