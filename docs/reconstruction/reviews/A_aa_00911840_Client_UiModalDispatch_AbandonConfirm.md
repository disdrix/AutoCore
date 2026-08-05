# Review A (reconstruction fidelity): `aa_00911840` Client_UiModalDispatch_AbandonConfirm

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911840` |
| **VA** | `0x00911840` |
| **Canonical name (claim)** | `Client_UiModalDispatch` (abandon-confirm **slice**); Ghidra `FUN_00911840` |
| **Review date** | `2026-07-29` |
| **Re-verify** | Live `decompile_function` `0x00911840` + `get_function_xrefs` / `get_assembly_context` (same day residual seal pass) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00911840_Client_UiModalDispatch_AbandonConfirm.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept-with-gaps** — residual cases **`0x4e46` / `0x4e47` sealed High**; full switch out of scope |

---

## 1. Purpose (scoped)

`FUN_00911840` is a **large global UI modal dispatcher** (`__thiscall`, switch on modal code `param_3`, event `param_2`). This review seals the **abandon mission confirm** residual slice only:

| Modal code | Event | Behavior | Confidence |
|---|---|---|---|
| **`0x4e46`** | `param_2 == 8` | **Yes / confirm abandon** → C2S **`0x20B2`** size **`0x18`** (if stash + character + def hit); optional mission UI chrome; **always** close modal | **High** |
| **`0x4e47`** | `param_2 == 8` | **No / dismiss** (shared dismiss family) → `FUN_007fc360()` **close only** — **no** sector packet | **High** |

Upstream stash + prompt open:

```
Client_MissionDialogHandleButton @ 0x008ae7c0  [dialog state 2, button==1]
  DAT_00d1b4b4 = **(dialog+0x670)  or  0xFFFFFFFF
  sprintf abandon prompt ("Are you sure you wish to abandon \"%s\"?")
  Client_ShowModalPrompt: EAX=0x4e46 (Yes), stack secondary=0x4e47 (No), flags 1,0
  // decompiler often shows only FUN_007fdfb0(..., 0x4e47, 1, 0)
  return 0
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `decompile_function` `0x00911840` — cases `0x4e46` / `0x4e47` re-extracted |
| Xrefs | `get_function_xrefs` → CALL `0x009140fe`, CALL `0x009257e9`, DATA `0x00a30694` |
| Call-site asm | `get_assembly_context` at both CALLs (`PUSH` args then `CALL 0x00911840`) |
| DATA slot | `read_memory` `0x00a30694` = dword `0x00911840` (fn-ptr table) |
| Slice clean | `reconstructed-exact/Client_UiModalDispatch_AbandonConfirm.cpp` |
| Full scaffold | `reconstructed-exact/FUN_00911840.cpp` |
| Function record | `functions/aa_00911840_Client_UiModalDispatch.md` |
| Upstream duals | `A/B_aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| Modal helper duals | `A/B_aa_007fdfb0_Client_ShowModalPrompt.md` (UF-009) |
| Mission table | `FUN_0053fff0` → returns `*(game+0xf18)` (lazy-alloc) |
| Close helper | `FUN_007fc360` — dismiss modal / restore `+0x498`/`+0x49c` backups |
| Downstream | C2S → server → S2C `Client_RecvFailMission` `0x0080b100` |

---

## 3. Residual case `0x4e46` (Yes → C2S `0x20B2`) — **SEALED**

Live decompile body (authoritative):

```c
case 0x4e46:
  if (param_2 == 8) {
    if ((DAT_00d1b4b4 != 0xffffffff) && (DAT_00d1b6d8 != 0)) {
      puVar7 = (undefined4 *)FUN_0053fff0();
      if (((void *)*puVar7 != (void *)0x0) &&
         (piVar8 = CNDHash_LookupByKey((void *)*puVar7, key), piVar8 != (int *)0x0)) {
        apiStack_460[0] = (int *)0x20b2;
        iVar9 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);
        uStack_458 = *(undefined4 *)(iVar9 + 0x164 + DAT_00d1b6d8);  // COID lo
        uStack_454 = *(undefined4 *)(iVar9 + 0x168 + DAT_00d1b6d8);  // COID hi
        uStack_450 = *piVar8;                                        // MissionId
        Client_SendSectorPacket(&DAT_00d1a840, 0x18, apiStack_460);
        if ((DAT_00d1b898 != (int *)0x0) &&
           (cVar2 = (**(code **)(*DAT_00d1b898 + 0x3d8))(), cVar2 != '\0')) {
          FUN_007fca10();
          FUN_007fef20(0x13, 1, 0);
        }
      }
    }
    FUN_007fc360();
    goto LAB_00911a99;
  }
  break;
```

### Sealed steps

1. `key = DAT_00d1b4b4` **snapshotted at function entry** (before `switch`).
2. On `param_2 == 8`:
3. If `DAT_00d1b4b4 != -1` **and** `DAT_00d1b6d8 != 0` (character live):
4. `puVar7 = FUN_0053fff0()` — mission definition table root object (`game+0xf18`).
5. If `*puVar7 != 0` and `CNDHash_LookupByKey(*puVar7, key)` hits:
6. Build packet on stack buffer starting at `apiStack_460`:
   - `[0] = 0x20b2` (literal opcode)
   - COID lo/hi from character dual-base `+0x164` / `+0x168`
   - Mission id = `*piVar8` (first dword of hash value / def node) — **not** raw global write-through
   - `Client_SendSectorPacket(&DAT_00d1a840, 0x18, packet)`
7. If mission UI object `DAT_00d1b898` reports live (`vtbl+0x3d8`): `FUN_007fca10()`; `FUN_007fef20(0x13, 1, 0)`.
8. **Always** `FUN_007fc360()` then shared exit (`LAB_00911a99`).

**No** call to `CVOGReaction_FailMission` in this function. Local fail is **not** applied on Yes.

### Packet layout (size `0x18`)

| Offset | Source | Field |
|---:|---|---|
| `+0x00` | literal `0x20B2` | Opcode FailMission |
| `+0x04` | stack pad (`apiStack_460[1]`) | pad4 (not explicitly zeroed) |
| `+0x08` | char dual-base `+0x164` | CharacterCoid lo |
| `+0x0C` | char dual-base `+0x168` | CharacterCoid hi |
| `+0x10` | `*piVar8` | MissionId |
| `+0x14` | stack pad | pad4 |

---

## 4. Residual case `0x4e47` (No → close-only) — **SEALED**

Live decompile multi-case group:

```c
case 0x4e45:
case 0x4e47:   /* abandon No — shared dismiss family */
case 0x4e4b:
case 0x4e4d:
case 0x4e4f:
case 0x4e52:
case 0x4e53:
case 0x4e55:
case 0x4e57:
case 0x4e59:
case 0x4e5b:
  if (param_2 == 8) {
    FUN_007fc360();
    goto LAB_00911a99;
  }
  break;
```

| Claim | Result |
|---|---|
| Sends any sector packet | **Falsified** — only `FUN_007fc360` |
| Mutates mission hashes / active list | **Falsified** — absent |
| Closes modal | **Sealed** — same close helper as Yes post-send |
| Shared with other cancel-class codes | **Sealed** — multi-case label list above |

Matches “cancel abandon” as **dismiss-without-send**.

---

## 5. Yes/No pairing (UF-009) — residual closed

| Fact | Source | Confidence |
|---|---|---|
| Open loads **EAX=`0x4e46`** (Yes) | HandleButton asm `008ae8be` `MOV EAX,0x4e46` | **High** |
| Open stack secondary **`0x4e47`** (No) | `PUSH 0x4e47` before `CALL FUN_007fdfb0` | **High** |
| Store Yes → host `+0x498`, No → `+0x49c` | `Client_ShowModalPrompt` dual-id write | **High** |
| Click Yes → dispatch case `0x4e46` → C2S | This function live decompile | **High** |
| Click No → dispatch case `0x4e47` → close only | This function live decompile | **High** |
| Decompiler open call omits EAX | Systematic decompiler stack-only view | **High** |

**Do not** assert “decompiler third arg == confirm.” Confirm is **`0x4e46`**; dismiss is **`0x4e47`**.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function is global modal switch on `param_3` | **High** | Huge case list |
| `param_2 == 8` is primary / confirm event | **Probable** | Universal pattern; no enum table recovered |
| Case `0x4e46` sends C2S `0x20B2` size `0x18` | **High** | Literal opcode + size |
| COID from char `+0x164/+0x168` | **High** | Same entity layout as FailMission log |
| Mission id from def-table lookup of entry snapshot `key` | **High** | `key` + `*node` |
| Stash `DAT_00d1b4b4` from HandleButton state 2 | **High** | Dual-reviewed sibling |
| Yes button code = `0x4e46` | **High** | EAX→`+0x498`; case sends C2S |
| Cancel = `0x4e47` close-only | **High** | stack→`+0x49c`; grouped dismiss |
| No local FailMission on confirm | **High** | Absent from case body |
| Entry via direct CALL sites + DATA fn-ptr | **High** | xrefs `009140fe` / `009257e9` / `00a30694` |
| Name covers only abandon | **Over-narrow** | Full function handles many modal codes |

---

## 7. Control flow: slice clean ≡ live case body

| Stage | Match |
|---|---|
| Gate stash ≠ −1 + character live | **Yes** |
| Mission table + hash lookup | **Yes** |
| Packet 0x20B2 / size 0x18 / COID / mission id | **Yes** |
| Optional `FUN_007fef20(0x13,1,0)` | **Yes** |
| Close modal always on confirm path | **Yes** |
| Cancel close-only | **Yes** (simplified in slice as standalone if) |

Slice file is intentional excerpt, not full dispatcher CF.

---

## 8. Entry vector (strengthened)

| Kind | Address | Notes |
|---|---|---|
| UNCONDITIONAL_CALL | `0x009140fe` | `PUSH EDX; PUSH ESI; CALL 0x00911840; POP ESI; RET 8` |
| UNCONDITIONAL_CALL | `0x009257e9` | `PUSH EAX; PUSH ESI; CALL 0x00911840; POP ESI; RET 8` |
| DATA (fn-ptr table) | `0x00a30694` | dword = `0x00911840` among sibling UI handlers |

Ghidra `get_function_callers` still returns empty (callers sit in unnamed / mid-function regions). **Not** evidence of dead code — xrefs seal liveness.

---

## 9. Gaps (remaining)

1. ~~**Yes/No id pairing residual**~~ **Sealed High (UF-009 + this dual).**
2. ~~**Residual case bodies `0x4e46`/`0x4e47`**~~ **Sealed High (live re-decompile).**
3. Named identity of outer functions containing CALL sites `009140fe` / `009257e9` (Ghidra: no containing function).
4. `FUN_0053fff0` `this` (game singleton) register not shown at call site in decompile of this function.
5. Whether `*hashValue` always equals key `DAT_00d1b4b4` (normally mission id == key).
6. Runtime abandon click observation (Yes → event `0x4e46` + C2S `0x20B2`).
7. Full dispatcher not dual-reviewed (out of scope).
8. `param_2 == 8` enum name / formal table still Probable.

---

## 10. Verdict

Abandon **confirm → C2S FailMission `0x20B2`** is **statically sealed**. Cancel dismiss is sealed. Pairing Yes `0x4e46` / No `0x4e47` is **High** (UF-009). Prefer product name `Client_UiModalDispatch` with abandon documented as a **slice**, not the whole function’s sole purpose.

**Verdict: accept-with-gaps** (slice sealed; full switch + runtime open).
