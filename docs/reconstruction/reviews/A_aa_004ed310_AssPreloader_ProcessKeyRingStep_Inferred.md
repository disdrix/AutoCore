# Review A (reconstruction fidelity): `aa_004ed310` AssPreloader_ProcessKeyRingStep_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ed310` |
| **VA** | `0x004ed310`–`0x004ed46b` (**348 B**) |
| **Canonical name** | `AssPreloader_ProcessKeyRingStep_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004ed310` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-A) |
| **Counterpart** | `reviews/B_aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md` |
| **System** | AssPreloader / client-fx preload key ring |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 348 B) + `analyze_function_complete` + xrefs; 4 callers / 8 sites; nested sealed duals W31-K/W32-J/W34-L |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Cooperative **preload key-ring step**: walk a GuardedVector of keys under global AssPreloader; erase already-tracked keys; enqueue first unready key+deps and yield; when progress flag set, wait (yield) until cache present or tree-ready, then advance. Return AL=1 when exhausted (or no preloader).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ed310_FUN_004ed310.md` (+ 2026-07-29 W35-A append) |
| Annotated | `docs/reconstruction/raw/aa_004ed310_FUN_004ed310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_ProcessKeyRingStep_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ed310.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ed310_FUN_004ed310.md` |
| Named record | `docs/reconstruction/functions/aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; plain RET; AL 0/1; gate DAT_00d1f050+0x6c |
| Nested duals | W31-K `00971900`; W32-J `009717a0`; W34-L `0043df90`; W35-A sibling `0043e630` via `00971030` |

---

## 3. Signature (sealed)

```c
// cdecl; 3 stack formals; plain RET; AL = 1 done / 0 yield
uint8_t AssPreloader_ProcessKeyRingStep_Inferred(
    GuardedVectorHeader* ring,
    char* progress_flag,
    uint32_t* cursor);
```

| Slot | Source | Conf |
|---|---|---|
| ring | Stack[+4] | **High** |
| progress_flag | Stack[+8] | **High** |
| cursor | Stack[+0xc] | **High** |
| cleanup | plain `RET` (caller `ADD ESP,0xC`) | **High** |
| return | **AL** | **High** |
| preloader | `*(DAT_00d1f050+0x6c)` as ECX for nested | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if *(cache+0x6c)==0: return 1
clamp *cursor
abs = ring->begin + *cursor
loop:
  if at end: clear cursor+flag; return 1
  slot = page_map(cur, abs)
  if IsKeyTracked(preloader, slot, 0):
    if flag: pending_remove(preloader, slot)
    EraseRange_Thiscall one-slot; resume out-iter; continue
  if flag==0:
    if !cache_present and !tree_ready:
      EnqueueKeyAndDeps; flag=1; return 0
  else:
    if !cache_present:
      if !tree_ready: return 0
      cursor++; abs++; continue
  cursor++; abs++
```

| Stage | Match | Conf |
|---|---|---|
| Preloader gate early return 1 | **Yes** | **High** |
| Cursor clamp | **Yes** | **High** |
| Tracked → optional 00971030 + erase | **Yes** | **High** |
| flag0 enqueue-yield | **Yes** | **High** |
| flag1 wait-yield / advance | **Yes** | **High** |
| Exhaust clear + return 1 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry gate:

```
A1 50 F0 D1 00    ; MOV EAX,[DAT_00d1f050]
83 EC 08          ; SUB ESP,8
83 78 6C 00       ; CMP [EAX+0x6C],0
75 06             ; JNZ cont
B0 01             ; MOV AL,1
83 C4 08 C3       ; ADD ESP,8; RET
```

Yield return:

```
32 C0             ; XOR AL,AL
5D 83 C4 08 C3    ; POP EBP; ADD ESP,8; RET
```

Done return:

```
B0 01             ; MOV AL,1
5D 83 C4 08 C3
```

Caller seal (`0054294x`): `PUSH; PUSH; PUSH; CALL 004ed310; ADD ESP,0xC; TEST AL,AL`.

Body length **348 B**. Full hex in raw W35-A append.

---

## 6. Gaps

- Product/PDB method English.
- Nested `0075d610` / `00971a20` / `00971030` product dual free (not owned this wave).
- Progress-flag product label (cooperative yield token sealed behaviorally).
- Runtime / bit-exact / concurrent ring mutation.

---

## 7. Verdict

ABI, global gate, page-map walk, tracked-erase / enqueue-yield / wait-yield CF sealed from live decompile + bytes + FxCache callers + nested sealed duals. Product residual → **accept-with-gaps**.
