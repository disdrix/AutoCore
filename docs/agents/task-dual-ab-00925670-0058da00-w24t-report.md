# Dual A/B report — W24-T OWN `aa_00925670` + `aa_0058da00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W24-T  
**Scope:** VAs `0x00925670`, `0x0058da00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00925670` Client_ItemPickup_AutoGatherTick | **accept-with-gaps** — CF/ABI/throttle/20.0f/pickup path sealed; gate English + full gather argc residual |
| `aa_0058da00` MapFloatTfid_FreeSubtree_Isnil29_Inferred | **accept** — byte CF (right+left walk) + isnil+0x29 + sole caller sealed; decompiler residual filled |

---

## VA `0x00925670` — sealed facts

1. **Body:** `0x00925670`–`0x00925712` (163 B; `RET 4`).
2. **ABI:** **EAX**=client* (`DAT_00d1b6d8` at call site); stack formal pushed by PollBound but **unused** in body; void return.
3. **Semantics:** If `client+0xcd0==0` and `GetTickCount` delta vs `DAT_00d1f0d4` **>99** (~100 ms): gather via vtbl+0x1a0(**20.0f**,1,6,0,0,1) + `FUN_0058cd60`; on valid TFID pair call `FUN_00925580` (`Client_SendItemPickup` / **0x2055**).
4. **Caller (1):** `Client_Input_PollBoundActions` @ site `0x00927894` (always-on path, not Activate-gated).
5. **Globals:** `DAT_00d1f0d4` throttle stamp; `DAT_00d218d4` tick sample; IAT GetTickCount `0x009c622c`.
6. **Name:** `Client_ItemPickup_AutoGatherTick` (Ghidra `FUN_00925670`).
7. **Decompile ≡ bytes** for CF; ABI residual (`void(void)` / `in_EAX`) corrected from epilog + call site.

### Gaps

- Product English for `+0xcd0` gate and vtbl+0x1a0 helper.  
- Full `FUN_0058cd60` formal list at this site (`add esp,0x2c`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00925670_Client_ItemPickup_AutoGatherTick.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00925670_Client_ItemPickup_AutoGatherTick.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00925670_FUN_00925670.md` |
| Annotated | `docs/reconstruction/raw/aa_00925670_FUN_00925670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ItemPickup_AutoGatherTick.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00925670.cpp` |
| Function | `docs/reconstruction/functions/aa_00925670_FUN_00925670.md` |
| Function named | `docs/reconstruction/functions/aa_00925670_Client_ItemPickup_AutoGatherTick.md` |
| Scratch | `docs/reconstruction/tmp/a_00925670.md` |

---

## VA `0x0058da00` — sealed facts

1. **Body:** `0x0058da00`–`0x0058da34` (53 B; `RET 4`).
2. **ABI:** stack `node*`; ECX threaded unused; void.
3. **CF (bytes override decompile):** if isnil@**+0x29** return; else loop recurse free **right+8**, `operator_delete` self, walk **left+0** until isnil.
4. **Caller (1 external):** `MapFloatTfid_EraseRange_Inferred` / `FUN_0058df60` @ `0x0058df7c` — free `head[1]` on full clear.
5. **Twin:** `StdMap_FreeSubtree_Isnil15_Inferred` @ `0x004ba770` (same CF; isnil **+0x15**).
6. **Name:** `MapFloatTfid_FreeSubtree_Isnil29_Inferred` (Ghidra `FUN_0058da00`).
7. **Reject:** chain-name PollBound scaffold alias as product name.
8. **Decompile incomplete** for left-walk; **bytes authoritative**.

### Gaps

- Product mangled `_Tree` English.  
- Value dtor / POD assumption.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0058da00_MapFloatTfid_FreeSubtree_Isnil29_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0058da00_MapFloatTfid_FreeSubtree_Isnil29_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0058da00_FUN_0058da00.md` |
| Annotated | `docs/reconstruction/raw/aa_0058da00_FUN_0058da00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MapFloatTfid_FreeSubtree_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058da00.cpp` |
| Function | `docs/reconstruction/functions/aa_0058da00_FUN_0058da00.md` |
| Function named | `docs/reconstruction/functions/aa_0058da00_MapFloatTfid_FreeSubtree_Isnil29_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0058da00.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00925670` | Client auto-loot tick — preserve 100 ms throttle, 20.0f/mode-6 gather family, and ItemPickup 0x2055 on hit; not Activate-edge exclusive. |
| `0058da00` | MapFloatTfid full-clear free — preserve right-first recurse + left walk + isnil@+0x29; do not trust collapsed decompiler. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.
