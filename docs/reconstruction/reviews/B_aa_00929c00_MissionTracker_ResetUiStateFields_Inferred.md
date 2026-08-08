# Review B (adversarial): `aa_00929c00` MissionTracker_ResetUiStateFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00929c00` |
| **VA** | `0x00929c00`–`0x00929c50` inclusive (**81 B** / `0x51`) |
| **Canonical name** | `MissionTracker_ResetUiStateFields_Inferred` |
| **Ghidra name** | `FUN_00929c00` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / falsification (OWN-ONLY MEGA-087) |
| **Counterpart** | `reviews/A_aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` |
| **System** | missions-progression / mission-tracker UI state |
| **Evidence pass** | Same live Ghidra set as Path A; adversarial claims tested against disasm, call sites, DAT bytes, parent decompiles. **No** `disassemble_bytes`. No Launcher. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Adversarial claims tested

| # | Claim | Result | Evidence |
|---|---|---|---|
| 1 | **thiscall / ECX = this** | **Falsified** | Callers `MOV EAX,EDI/ESI` then CALL; body uses ECX only as zero (`XOR ECX,ECX`); no `MOV ECX,reg` this setup |
| 2 | **cdecl stack `this*`** | **Falsified** | Bare `C3` (not `RET n`); no stack loads; 0 params in analyze |
| 3 | **void return / ignore EAX** | **Falsified** | `MOV AL,1` before RET; parents treat as success path |
| 4 | **Full tracker ctor / zero-entire-object** | **Falsified** | Writes only specific offsets; leaves `+0x0..+0x14`, `+0x10` mission id (parent-owned), vector `+0x11c`, etc. untouched |
| 5 | **Mission dialog button handler** (scaffold `Named_CalleeOf_*MissionDial*`) | **Falsified** | Xrefs only from `0092a590` / `0092c080`; dialog chain is separate (`0x008ae7c0` family) |
| 6 | **Integer store of `DAT_00aaa6fc` (not float)** | **Falsified** | `MOVSS` load + `MOVSS` store; bytes `00 00 C8 41` = 25.0f |
| 7 | **Same as inlined plate at start of `0092c080` only — dead helper** | **Falsified** | Live CALL at `0x0092c47f` on region change; also 2 live calls from `0092a590` |
| 8 | **ECX = client / global singleton** | **Falsified** | Object is tracker (EDI/ESI from parent); bind dual places tracker at client+`0x4d0` |
| 9 | **Callees exist / non-leaf** | **Falsified** | analyze callees=[]; no CALL opcodes in body |
| 10 | **Body extends past `0x00929c50`** | **Falsified** | RET at `0x00929c50`; next bytes `CC` pad then unrelated `85 F6…` |

---

## 2. Residual risks (accepted gaps)

| Risk | Severity | Notes |
|---|---|---|
| Product English for offsets | Medium | Role sealed; labels open |
| RTTI class name | Low–Med | Structural tracker identity High via bind dual |
| Parent residual duals | Low | Not required to seal this leaf CF/ABI |
| Runtime Confirmed | Open | Terminal false by OWN rules |

---

## 3. Odd behavior preserved

- Always returns **1** even on pure clear (no failure path inside leaf).
- Parent `FUN_0092c080` **duplicates** the same field plate at entry **and** re-invokes this helper on region delta — intentional shared reset, not dead code.
- Uses **SSE** (`MOVSS`) for a single float while rest is integer GPR — image quirk preserved in clean.

---

## 4. Cross-check vs Path A

| Topic | A | B |
|---|---|---|
| Body / CF | sealed | agrees |
| EAX ABI | sealed | agrees; thiscall falsified |
| Float 25.0f | sealed | agrees |
| Name `_Inferred` | yes | agrees (product English open) |
| Verdict | accept-with-gaps | **accept-with-gaps** |

No Path-A claim required rejection. Scaffold mission-dialog name remains retired.

---

## 5. Verdict

**accept-with-gaps** — adversarial alternatives that would force reject (wrong ABI, wrong object, dialog misname as sole identity, non-leaf) are falsified. Remaining gaps are product dictionary / runtime only.
