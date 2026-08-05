# Review B (skeptical / adversarial): `aa_00574760` ConvoyRoster_GetMemberBySlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574760` |
| **VA** | `0x00574760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create**) |
| **Counterpart** | `reviews/A_aa_00574760_ConvoyRoster_GetMemberBySlot_Inferred.md` |
| **Verdict** | **accept-with-gaps** — body + slot math sealed; product type name open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Hidden logic / multi-path body | Decompiler elision | **Falsified** — 11-ins linear; only bounds + load |
| 2 | Index range is 1..4 or 0..3 inclusive-end-4 | Off-by-one | **Falsified** — `cmp 4; jge fail` ⇒ valid **0..3** only |
| 3 | Base is `this+0x1a` not `0x1a0` | Misread `(i+0x1a)*0x10` | **Falsified** — `add 0x1a; shl 4` = `*16` after add |
| 4 | Pure `ret` / zero stack args | Confuse with 00574900 | **Falsified** — `ret 4`; loads `[esp+4]` |
| 5 | Returns float / share | OnDeathAward passes float SSA | **Falsified** — dword load; float is decompiler SSA for index counter at **caller** |
| 6 | Same as vehicle `entity+0x1a0` controller holder | Offset collision | **Sustained risk only for wrong type** — same numeric offset on **different** object; convoy roster ≠ VehicleEntity drive holder |
| 7 | `this` is always killer character | Ignore `+0xcb0` | **Partially falsified** — many sites only call when `char+0xcb0 != 0`; ECX typically roster |
| 8 | Writes / mutates roster | Side-effect invent | **Falsified** — load-only |
| 9 | Product name sealed | Over-promote | **Sustained** — keep `_Inferred` |
| 10 | Dead / unused | Drop from maps | **Falsified** — 30 CALL xrefs / 16 callers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Machine CF + formula | **High** | Wrong port of slot array |
| Valid index 0..3 | **High** | OOB read in port |
| `ret 4` ABI | **High** | Stack imbalance |
| Read-only getter | **High** | Fake mutations |
| Result is object ptr at use sites | **High** | Wrong cast |
| `this` = convoy at `char+0xcb0` | **Probable** | Wrong owner object |
| Slot payload beyond dword0 | **Open** | Incomplete struct |
| English product name | **Low** | Bad NAMING promote |

---

## 3. Cross-check against raw + bytes

```text
// clean ≡ raw ≡ live ≡ machine
// 00574760: mov eax,[esp+4]; bounds; add 0x1a; shl 4; mov eax,[eax+ecx]; ret 4
// fail: xor eax,eax; ret 4
undefined4 __thiscall ConvoyRoster_GetMemberBySlot_Inferred(void* roster, int index)
{
  if (index > -1 && index < 4)
    return *(undefined4*)((char*)roster + (index + 0x1a) * 0x10);
  return 0;
}
```

Hex head: `8b 44 24 04 83 f8 ff 7e 11 83 f8 04 7d 0c 83 c0 1a c1 e0 04 8b 04 08 c2 04 00 33 c0 c2 04 00`.

---

## 4. Surviving contract for AutoCore

```
ConvoyRoster_GetMemberBySlot_Inferred(roster, index):
  if index not in [0,3]: return null
  return *(roster + 0x1a0 + index*0x10)   // member object* or null

// Do NOT:
//  - treat as vehicle controller holder at entity+0x1a0
//  - invent writes / iteration / distance tests (those are callers / 00574e60)
//  - assume index is float (caller SSA only)
```

**Port tests:** OOB → null; index 0..3 load only; stack pops 4 bytes; no callee.

---

## 5. Open questions

1. Exact C++ class of roster (`char+0xcb0` target).
2. Full 0x10-byte slot layout (only dword0 consumed here).
3. Whether all 30 call sites pass the same roster type (static CF suggests yes).
4. Runtime / differential (policy).
5. PDB symbol.

**Verdict:** **accept-with-gaps** — adversarial attacks on formula, ABI, and side effects **closed**; type/name remain open.
