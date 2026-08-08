# Review A (reconstruction fidelity): `aa_00574880` ConvoyRoster_GetLeaderMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574880` |
| **VA** | `0x00574880`–`0x0057489b` inclusive (**28 B** / `0x1c`) |
| **Canonical name** | `ConvoyRoster_GetLeaderMember_Inferred` |
| **Ghidra name** | `FUN_00574880` |
| **Prior alias** | `Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_00574880` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A — WQ9F-I) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` |
| **System** | convoy / crew roster |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

**Leader member pointer load.** On a convoy/crew roster host:

1. If member-count byte `this+0x1d8 == 0`, return **null**.
2. Else load leader slot index from `this+0x194` and return the dword at `this + (index + 0x1a) * 0x10` (same algebra as `ConvoyRoster_GetMemberBySlot_Inferred`, **without** 0..3 bounds).

Call sites treat the result as a **character/member object*** and compare to `DAT_00d1b6d8` (local player) for **leader** gates (Invite/Kick disable, etc.).

```c
// ECX = roster; no stack args; plain RET; EAX = member* or null
void *ConvoyRoster_GetLeaderMember_Inferred(void *roster);
```

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Live decompile | Ghidra @ `0x00574880` | **≡** raw |
| Live bytes | `read_memory` 28 B | full leaf + pad start |
| Live disasm | `disassemble_function` | 9 ins; dual exits |
| Callers / xrefs | analyze complete | **10** UNCONDITIONAL_CALL |
| Twin | `aa_00574760` GetMemberBySlot | shared `(i+0x1a)*0x10` |
| Crew peers | ContainsMember / ClearMember | same `+0x198` table host |
| UI consumer | `aa_0082fb30` Invite/Kick dual | leader-disable sealed |
| Raw / annotated / clean | trio | refined |

**Not performed:** Launcher, runtime golden, parent ledgers.

---

## 3. Machine proof

**Live decompile (2026-08-04):**

```c
undefined4 __fastcall FUN_00574880(int param_1)
{
  if (*(char *)(param_1 + 0x1d8) == '\0') {
    return 0;
  }
  return *(undefined4 *)((*(int *)(param_1 + 0x194) + 0x1a) * 0x10 + param_1);
}
```

**Disassembly / bytes:**

```text
00574880  cmp  byte ptr [ecx+0x1d8], 0
00574887  ja   0057488c
00574889  xor  eax, eax
0057488b  ret
0057488c  mov  eax, [ecx+0x194]
00574892  add  eax, 0x1a
00574895  shl  eax, 4
00574898  mov  eax, [eax+ecx]
0057489b  ret
```

Hex: `80b9d801000000770333c0c38b819401000083c01ac1e0048b0408c3`

| Fact | Evidence | Conf |
|---|---|---|
| ECX = this (roster) | all loads use ECX base | **High** |
| No stack args | plain `C3`; no `[esp+…]` | **High** |
| Count gate `+0x1d8` | CMP/JA zero → null | **High** |
| Leader index `+0x194` | MOV from imm | **High** |
| Slot base algebra | `+0x1a` then `*0x10` | **High** |
| Returns object* | dword load; null-checked / CMP local at callers | **High** |
| Leader English | Invite/Kick dual + ADV spotcheck | **High** (role) / spelling **Inferred** |

---

## 4. Call-site sample (leader gate pattern)

| Site | Pattern after CALL |
|---|---|
| `0x0082fbaa` / `0x0082fc13` | `CMP EAX, [DAT_00d1b6d8]` → disable Invite/Kick btn via `vtbl+0xD4(0)` |
| `0x00830fa6` | same local CMP disable chain |
| `0x008a36a1` | equal-to-local enables path |
| `0x0093a199` | CMP EAX to drive-host `ESI+0xe98` |

All sites load ECX from `*(local+0xCB0)` or equivalent crew-host back-link before CALL.

---

## 5. Naming

| Name | Status |
|---|---|
| `ConvoyRoster_GetLeaderMember_Inferred` | **Structural inferred** (pairs GetMemberBySlot + leader index field) |
| `FUN_00574880` | scaffold alias |
| Prior mission-detail callee plate | **reject** as product |
| VehicleCrew_* alternate family | acceptable alias family (shared host); prefer ConvoyRoster for slot twin |

---

## 6. Gaps (acceptable)

1. Product demangle / Convoy vs VehicleCrew class English.
2. No body clamp to 0..3 — corrupt `+0x194` OOB risk (retail trusts writers).
3. Full product verb inventory for all 10 call sites.
4. Runtime / bit-exact / differential — open (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| Bytes seal count gate + slot load | **Pass** |
| Twin GetMemberBySlot algebra | **Pass** |
| Leader gate consumers documented | **Pass** |
| Clean uses meaningful names | **Pass** |
