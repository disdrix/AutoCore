# Review B (adversarial): `aa_00790020` Client_Input_KeyDown_UiGateAndForward_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00790020` |
| **VA** | `0x00790020`–`0x00790098` (**121 B** / `0x79`) |
| **Canonical name** | `Client_Input_KeyDown_UiGateAndForward_Inferred` |
| **Ghidra name** | `FUN_00790020` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / falsification (OWN-ONLY MEGA-094) |
| **Counterpart** | `reviews/A_aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` |
| **System** | `input-drive-control` |
| **Evidence pass** | Live Ghidra decompile + disasm + callers/xrefs + `read_memory` + parent/modal cross-checks. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Attack surface (claims under test)

| # | Claim under attack | Result |
|---|---|---|
| 1 | Function **remaps / normalizes** key codes (DIK rewrite) | **Falsified** — no store to key; return is 0/1 gate byte; parent still uses original key for table scan |
| 2 | **stdcall** / bare RET / wrong stack pop | **Falsified** — four `C2 08 00` exits; two stack args |
| 3 | **fastcall** / key in EDX | **Falsified** — `MOV ESI,ECX`; key from `[ESP+0xC]` after `PUSH EDI` |
| 4 | ESC path is only cancel; no modal dispatch | **Falsified** — when `+0x4BC==0` and `+0x49C>=0`, calls `vtbl+0x338(8, code)` |
| 5 | `+0x49C` is primary OK id (`+0x498`) | **Falsified** — index `0x127` → `0x49C` secondary (UF-009 / `a_007fdfb0`) |
| 6 | Leaf / no side effects | **Falsified** — up to three vcalls (gate, forward, cancel/dispatch) |
| 7 | Only callee of OnKeyDown_MatchAction | **Falsified** — also `FUN_00866220`, `FUN_008cc420`, ~150 DATA vtbl installs |
| 8 | Merge with pure ESC cancel in parent (`vtbl+0x3d8 && key==0x1b` branch) | **Falsified** — parent takes separate ESC path **before** calling this; this still handles ESC when parent falls through |
| 9 | Product demangle sealed without `_Inferred` | **Open/gap** — no string/RTTI name recovered for this symbol |

---

## 2. Fidelity cross-check

| Check | Result |
|---|---|
| Live decompile ≡ 2026-07-23 raw body | **Match** |
| Disasm offsets `+0x4BC` / `+0x49C` ≡ decomp indices `0x12f` / `0x127` | **Match** (`0x12f*4=0x4BC`, `0x127*4=0x49C`) |
| Imm `0x1B` ESC | **Match** |
| `PUSH 8` before `vtbl+0x338` | **Match** modal action family |
| Parent call site `0x009113c9` | **Match** UNCONDITIONAL_CALL |

---

## 3. Residual risks (not falsifications of CF)

1. English for focused UI at `+0x4BC` — structural pointer only.  
2. Whether `vtbl+0x3D8` is exactly "UI visible" vs broader "input allowed" — parent plate says UI cancel gate; DriveControlTick map uses same slot family for input block — product string open.  
3. Modal dispatch return width (AL-only vs full EAX) — decomp `undefined4`; asm leaves EAX from callee.  
4. Runtime Confirmed not claimed.

---

## 4. Naming

Scaffold `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020` **retired** (parent-only name understates multi-caller + virtual role).  
Inferred name states **UI gate + forward + ESC** without inventing product demangle.

---

## 5. Verdict

Adversarial claims against ABI/CF/ESC/modal path **fail**. Residual is product English only → **accept-with-gaps** (aligned with Path A).
