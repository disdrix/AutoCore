# Review A (reconstruction fidelity): `aa_005208c0` CVOGCharacter_SetQuickBarSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_005208c0` |
| **VA** | `0x005208c0` |
| **Canonical name** | `CVOGCharacter_SetQuickBarSkill` |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| **System** | `skills-abilities` |
| **Prior dual quality** | Thin batch stub (`accept` trivial, 2026-07-23) — no byte seal, no caller table, incomplete function record |
| **Verdict** | **accept** — kernel CF + layout + convention sealed; empty-sentinel product English remains producer-dependent |

---

## 1. Purpose

Client **local quick-bar skill-id setter** on a character object:

1. Guard: `slot` (byte) **unsigned** compare `< 100` (`0x64`); else pure no-op (no dirty).
2. Store `skillId` (**int32**) at `this + 0x74c + slot * 4`.
3. `*(uint32*)(this + 0x634) |= 2` — shared quick-bar dirty bit (same bit as `CVOGCharacter_SetQuickBarItem`).
4. Return void; **`ret 8`** (cleans `slot` + `skillId`).

No packet I/O, no item COID touch, no callees. Sibling item path is `aa_00520890` @ `+0x930` stride 8.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `decompile_function` `0x005208c0` (2026-07-29 residual) |
| Live Ghidra `read_memory` | entry `0x005208c0` length 48 — full body decoded from bytes |
| Function metadata | `get_function_by_address` — body `005208c0`–`005208df` |
| Callers | `get_function_callers` + `get_xrefs_to` |
| Raw | `docs/reconstruction/raw/aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| Annotated | `docs/reconstruction/raw/aa_005208c0_CVOGCharacter_SetQuickBarSkill.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetQuickBarSkill.cpp` |
| Function record | `docs/reconstruction/functions/aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| Sibling | `aa_00520890` SetQuickBarItem (shared dirty bit 2) |
| Product note | `docs/skills-quickbar.md` (create restore + empty conventions) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(this, byte slot, int skillId)` + `ret 8` | **High** | Decomp + bytes `c2 08 00` |
| Boundary `005208c0`–`005208df` (~32 B) | **High** | `get_function_by_address` |
| Guard `slot < 100` unsigned (`cmp al,64h` / `jae`) | **High** | Bytes `3c 64 73 15` |
| Store `*(int32*)(this+0x74c+slot*4) = skillId` | **High** | `89 94 81 4c 07 00 00` |
| Dirty `*(uint32*)(this+0x634) \|= 2` | **High** | `83 89 34 06 00 00 02` |
| No callees / pure local store | **High** | Body + decomp |
| Shared dirty bit with SetQuickBarItem | **High** | Sibling body identical OR |
| Array length 100 (slots 0..99) | **High** | Guard + create restore 100×int32 @ pkt `0x730` |
| Empty skill = `-1` **or** `0` | **Producer-dependent** | Clear UI uses `-1`; server/create empty often `0` |
| Dirty bit product English (“QB chrome refresh”) | **Probable** | Writer sealed; full reader set open |
| Bit-exact / runtime golden | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live Ghidra ≡ bytes

| Stage | Match |
|---|---|
| Load `slot` from `[esp+4]` | **Yes** |
| `cmp` / `jae` skip when `slot >= 100` | **Yes** |
| Load `skillId` from `[esp+8]` | **Yes** |
| `movzx` + store at `+0x74c + slot*4` | **Yes** |
| `or [this+0x634], 2` | **Yes** |
| `ret 8` | **Yes** |
| No invented branches / no packet / no item write | **Yes** |

**Result:** Kernel CF sealed. Residual pass closed thin dual gaps (bytes, convention, callers).

---

## 5. Machine seal (`read_memory` @ `0x005208c0`)

```
8a 44 24 04          mov  al, [esp+4]           ; slot
3c 64                cmp  al, 0x64              ; 100
73 15                jae  short skip            ; no-op path
8b 54 24 08          mov  edx, [esp+8]          ; skillId
0f b6 c0             movzx eax, al
89 94 81 4c 07 00 00 mov  [ecx+eax*4+0x74c], edx
83 89 34 06 00 00 02 or   dword ptr [ecx+0x634], 2
c2 08 00             ret  8
; skip: falls into ret 8
```

---

## 6. Call-site context (Ghidra, 2026-07-29)

| Caller | Address | Role (static) |
|---|---:|---|
| `Client_RecvCreateCharacter` | `0x008146b0` | Login restore — skill array from CreateCharacterExtended @ pkt `0x730` |
| `Client_SkillTrainUiRequest_INFERRED` | `0x00897170` | First-rank auto-map into empty QB skill slot |
| `QuickBar_ClearActiveSlot_INFERRED` | `0x008274c0` | Clear selected slot skill with **`skillId = -1`** |
| `FUN_00826860` | `0x00826860` | QB UI assign path family |
| `FUN_00827670` | `0x00827670` | QB UI assign path family |
| `FUN_008283a0` | `0x008283a0` | QB UI path (also clears skill `-1` in related sequences) |
| `FUN_008285a0` | `0x008285a0` | QB UI path family |
| Xref `0x008290d1` | (no named function boundary in Ghidra) | Additional call site; not required for kernel seal |

This unit **does not** send `QuickBarUpdate 0x2062`; callers that persist do so separately (`Client_SendQuickBarUpdate*`).

---

## 7. Gaps (after residual)

1. ~~Offsets / dirty / bounds / ret bytes~~ **Sealed** via `read_memory`.
2. ~~Caller inventory~~ **Sealed** (static Ghidra list).
3. Empty skill sentinel product single value (`0` vs `-1`) — **producer-dependent** (not enforced here).
4. Full readers of `char+0x634` bit `2` (UI tick / serialize).
5. Bit-exact / runtime observation of live local char layout.

---

## 8. Verdict

**SetQuickBarSkill kernel is sealed** for bound check, skill-id array layout, shared dirty bit 2, and thiscall footprint. Residual dual upgrades thin 2026-07-23 stubs to byte-backed High confidence.

**Verdict: accept** (kernel + layout + convention) — empty-sentinel English and dirty readers remain outside this unit.
