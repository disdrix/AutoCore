# Annotated low-level: CVOGReaction_UnlockContinentObject

| Field | Value |
|---|---|
| Stable ID | `aa_00531c80` |
| VA | `0x00531c80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00531c80`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CVOGReaction_UnlockContinentObject: exploration/continent unlock hash at char+0x534.

   Also called from Client_RecvUnlockRegion (0x205B fog) and GiveMission/CompleteObjective.

   Distinct from reaction type 32 UnlockContObj (map object unlock via 0x206C GroupReactionCall). */



void __thiscall CVOGReaction_UnlockContinentObject(void *this,uint continentId)



{

  int iVar1;

  uint *value;

  undefined1 local_138 [28];

  undefined4 local_11c;

  int pHashNode;

  

  pHashNode = *(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x534) + 0x10) +

                               (*(uint *)(*(int *)((int)this + 0x534) + 8) & continentId) * 4) + 4);

  do {

    if (pHashNode == 0) {

LAB_00531cc8:

      value = operator_new(0xc);

      *value = continentId;

      *(undefined1 *)(value + 1) = 1;

      value[2] = 0;

      CNDHash_Insert(*(void **)((int)this + 0x534),continentId,value,'\0');

      pHashNode = *(int *)(*(int *)((int)this + 4) + 4);

      iVar1 = *(int *)((int)this + pHashNode + 0xa8);

      if ((iVar1 != 0) && ((int)this + pHashNode + 4 == *(int *)(iVar1 + 0xe8a0))) {

        FUN_004d1d00();

        local_11c = 0x2a;

        FUN_004d9ec0(local_138,1);

      }

      return;

    }

    if (continentId == *(uint *)(pHashNode + 0x10)) {

      if ((pHashNode != 0) && (*(int *)(pHashNode + 8) != 0)) {

        return;

      }

      goto LAB_00531cc8;

    }

    pHashNode = *(int *)(pHashNode + 0xc);

  } while( true );

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
