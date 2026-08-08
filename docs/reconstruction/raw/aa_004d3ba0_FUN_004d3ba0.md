# Raw capture: FUN_004d3ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d3ba0` |
| **Canonical name** | `FUN_004d3ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint FUN_004d3ba0(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  void *pvVar10;
  uint *puVar11;
  byte local_21;
  int iStack_20;
  undefined1 local_18 [4];
  int *local_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2059;
  pvStack_c = ExceptionList;
  local_21 = 0;
  ExceptionList = &pvStack_c;
  local_14 = (int *)FUN_0040fb90();
  local_10 = 0;
  puVar5 = *(undefined4 **)(param_1 + 0x1d8);
  local_4 = 0;
  if ((puVar5 != (undefined4 *)0x0) && (*(int *)(param_1 + 0x1dc) - (int)puVar5 >> 3 != 0)) {
    if ((puVar5 == (undefined4 *)0x0) || (*(int *)(param_1 + 0x1dc) - (int)puVar5 >> 3 == 0)) {
      puVar5 = (undefined4 *)FUN_004e0eb0();
    }
    piVar6 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar5,puVar5[1]);
    if (((piVar6 != (int *)0x0) && ((**(code **)(*piVar6 + 0x124))(local_18), local_10 != 0)) &&
       (iVar1 = *(int *)(*local_14 + 8), *(int *)(*(int *)(iVar1 + 0xa8) + 0x38) == 0x12)) {
      iVar8 = *(int *)(param_2 + 0x540);
      iStack_20 = 0;
      if (*(char *)(iVar8 + 0x1d) != '\0') {
        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      *(undefined1 *)(iVar8 + 0x1d) = 1;
LAB_004d3cb0:
      do {
        do {
          do {
            iVar8 = *(int *)(param_2 + 0x540);
            if (*(char *)(iVar8 + 0x1d) == '\0') {
              FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
              FUN_007a4480(0,"VOG_DEBUG_STOP");
            }
            if (iStack_20 == 0) {
              iStack_20 = *(int *)(iVar8 + 0x14);
              if (iStack_20 == 0) goto LAB_004d3cff;
              puVar11 = *(uint **)(iStack_20 + 8);
            }
            else {
              iStack_20 = *(int *)(iStack_20 + 0x14);
              if (iStack_20 == 0) {
LAB_004d3cff:
                puVar11 = (uint *)0x0;
              }
              else {
                puVar11 = *(uint **)(iStack_20 + 8);
              }
            }
            if (puVar11 == (uint *)0x0) {
              *(undefined1 *)(*(int *)(param_2 + 0x540) + 0x1d) = 0;
              piVar6 = (int *)*local_14;
              *local_14 = (int)local_14;
              local_14[1] = (int)local_14;
              local_10 = 0;
              if (piVar6 == local_14) {
                    /* WARNING: Subroutine does not return */
                operator_delete(local_14);
              }
                    /* WARNING: Subroutine does not return */
              operator_delete(piVar6);
            }
            iVar8 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0x530) + 0x10) +
                                     (*(uint *)(*(int *)(param_2 + 0x530) + 8) & *puVar11) * 4) + 4)
            ;
            if (iVar8 == 0) {
LAB_004d3d35:
              iVar8 = 0;
            }
            else {
              do {
                if (*puVar11 == *(uint *)(iVar8 + 0x10)) {
                  if (iVar8 == 0) goto LAB_004d3d35;
                  iVar8 = *(int *)(iVar8 + 8);
                  goto LAB_004d3d3c;
                }
                iVar8 = *(int *)(iVar8 + 0xc);
              } while (iVar8 != 0);
              iVar8 = 0;
            }
LAB_004d3d3c:
          } while (iVar8 == 0);
          uVar7 = *(uint *)(iVar8 + 0x20);
          if (uVar7 == 0xffffffff) {
            uVar7 = puVar11[0x22];
          }
        } while (uVar7 != *(uint *)(*(int *)(iVar1 + 0xa8) + 0x34));
        uVar7 = *(uint *)(iVar8 + 0x24);
        if (uVar7 == 0xffffffff) {
          uVar7 = puVar11[0x3f];
        }
      } while (((uVar7 != *(uint *)(*(int *)(iVar1 + 0xa4) + 0xfc)) || ((byte)puVar11[0x4c] == 0))
              || (iVar8 = *(int *)((puVar11[0x4f] - 4) + (uint)(byte)puVar11[0x4c] * 4), iVar8 == 0)
              );
      if (*(int *)(iVar8 + 0x138) == 0) {
        if (local_21 < 5) {
          local_21 = 4;
        }
        goto LAB_004d3cb0;
      }
      piVar6 = *(int **)(iVar8 + 0x158);
      bVar3 = true;
      bVar2 = true;
      if (piVar6 != *(int **)(iVar8 + 0x15c)) {
        do {
          iVar9 = (**(code **)(*(int *)*piVar6 + 0x50))();
          if ((iVar9 == 3) && (*(int *)(*piVar6 + 0x18) != *(int *)(*(int *)(iVar1 + 0xa8) + 0x34)))
          {
            bVar2 = false;
          }
          pvVar10 = CNDHash_LookupByKey(*(void **)(param_2 + 0x55c),*(uint *)(iVar8 + 0x10));
          if ((pvVar10 == (void *)0x0) ||
             (cVar4 = (**(code **)(*(int *)*piVar6 + 0xc))(param_2,pvVar10), cVar4 == '\0')) {
            bVar3 = false;
          }
          piVar6 = piVar6 + 1;
        } while (piVar6 != *(int **)(iVar8 + 0x15c));
        if ((!bVar2) || (!bVar3)) {
          if (local_21 < 6) {
            local_21 = 5;
          }
          goto LAB_004d3cb0;
        }
      }
      if (local_21 < 9) {
        local_21 = 8;
      }
      goto LAB_004d3cb0;
    }
  }
  uVar7 = FUN_00403430();
  ExceptionList = pvStack_c;
  return uVar7 & 0xffffff00;
}
```


---

## MEGA-069 live re-verify (APPEND ONLY) — 2026-08-05

**Agent:** OWN-ONLY dual MEGA-069  
**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `analyze_control_flow`. **No** `disassemble_bytes`. No Launcher.  
**Image:** `autoassault.exe` base `0x400000`.

### Body / metrics

| Item | Value |
|------|-------|
| Range | `0x004d3ba0`–`0x004d3ee2` inclusive (**835 B** / `0x343`) |
| Pad | `CC` at `0x004d3ee3`… then `FUN_004d3ef0` |
| Classification | worker |
| BB / edges / insn | 61 / 106 / 237 (Ghidra CF) |
| Cyclomatic | 47 (very_high) |
| Returns | 2 sites (early fail + post-traversal); both `RET 8` |

### ABI (assembly-sealed; corrects decompiler)

```text
004d3ba0  PUSH -1 / SEH LAB_009a2059 / FS:[0]
004d3bb5  SUB  ESP, 0x18
004d3bb8  PUSH ESI
004d3bb9  MOV  ESI, ECX              ; this = host (parent EDI)
...
004d3bd4  MOV  ECX, [ESP+0x30]       ; stack arg1 = child reaction
004d3bd8  MOV  EAX, [ECX+0x1d8]      ; child target pair vector begin
...
004d3c16  MOV  ECX, [ESI+0xe4e8]     ; this+0xe4e8 ? ResolveObjectTarget this
004d3c1f  CALL CVOGReaction_ResolveObjectTarget (0x004bae70)
...
004d3c60  XOR  AL, AL                ; early fail return 0
004d3c71  RET  8                     ; C2 08 00
...
004d3c76  MOV  EBP, [ESP+0x3c]       ; stack arg2 = character (after PUSH EBX/EBP)
...
004d3ecd  MOV  AL, [ESP+0x0f]        ; best-state byte (local_21)
004d3ee0  RET  8                     ; C2 08 00
```

| Slot | Machine | Conf |
|------|---------|------|
| this | **ECX** at entry ? ESI; used as `this+0xe4e8` only | **High** |
| child_reaction | stack `[ESP+4]` at entry; parent `PUSH ESI` | **High** |
| character | stack `[ESP+8]`; parent `PUSH EBP`; body uses `+0x540/+0x530/+0x55c` | **High** |
| cleanup | **`RET 8`** (`C2 08 00`) ×2 | **High** |
| return | **AL** ? {**0**, **4**, **5**, **8**} | **High** |

**Decompiler defects (do not trust):**
1. Signature drops **ECX this** — displays `uint FUN_004d3ba0(int,int)` only.
2. Final `return uVar7 & 0xffffff00` is **false** — epilog is `MOV AL, best; RET 8`.
3. `operator_delete` marked noreturn — actually frees resolved-target list nodes then returns AL.
4. `FUN_00403430` is list dtor (ECX=list), not the return source.

### Callers / xrefs

| Kind | Value |
|------|-------|
| Callers | **1** — `CVOGObject_EvalInteractStateFromChildren` @ `0x004d7640` |
| Xrefs | **2** UNCONDITIONAL_CALL @ `0x004d7806`, `0x004d7813` |
| Site gate | child type byte `[child+0x1d1] == 0x25` |
| Site use | max-aggregate into BL; if AL > BL re-call and `MOV BL, AL` |

### Callees (live)

`FUN_0040fb90` (list ctor), `FUN_004e0eb0` (empty-vector fallback), `CVOGReaction_ResolveObjectTarget` (`0x004bae70`), vcall `+0x124` (fill target list), `FUN_007a4480` (HashError / VOG_DEBUG_STOP diagnostics), `CNDHash_LookupByKey` (`0x005b0920`), requirement vcalls `+0x50` / `+0xc`, `FUN_00403430` (list dtor), `operator_delete` (`0x00489822`).

### Semantics (CF sealed)

1. SEH + empty best-state `local_21 = 0`.
2. Require non-empty child pair-vector `[child+0x1d8, child+0x1dc)` (element size 8).
3. Resolve first pair via `CVOGReaction_ResolveObjectTarget(this+0xe4e8, pair.a, pair.b)`.
4. Vcall `+0x124` fills local list; require non-empty; first entry object type `[+0xa8]+0x38 == 0x12`.
5. TraversalLock character object-hash `character+0x540` (byte `+0x1d`); walk chain `+0x14`.
6. Per object key: bucket walk on `character+0x530`; match key `+0x10` ? value `+0x8`.
7. Continent match: entry `+0x20` or object `+0x88` vs NPC MI `+0x34`.
8. Region match: entry `+0x24` or object `+0xfc` vs `character[+0xa4]+0xfc`.
9. Require object action-count `+0x130 > 0`; take last action ptr from `+0x13c` vector.
10. Score into best (max):
    - action `+0x138 == 0` ? raise best to **4**
    - else walk reqs `[+0x158, +0x15c)`:
      - vcall `+0x50`; if type **3** and req `+0x18 !=` NPC MI `+0x34` ? continent-fail
      - `CNDHash_LookupByKey(character+0x55c, action+0x10)` + vcall `+0xc(character, entry)` ? predicate
      - any fail ? raise best to **5**; all pass / empty ? raise best to **8**
11. Unlock traversal; free list; return best AL (0 if never raised).

### Strings (diagnostic only — not purpose)

- `HashError:TraversalLock, already locked for traversal`
- `HashError:TraverseToNext, not locked for traversal`
- `VOG_DEBUG_STOP`

### Live decompile note

Live `decompile_function` CF matches scaffold raw body structure (vector gate ? resolve ? type-0x12 ? hash traverse ? score 4/5/8). ABI/return corrected via assembly as above. Scaffold name `Named_VOG_DEBUG_STOP_004d3ba0` **retired**.

### Name promotion

`CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` — sole parent type-`0x25` deliver/use helper; return set {0,4,5,8}; product English open ? `_Inferred`.
