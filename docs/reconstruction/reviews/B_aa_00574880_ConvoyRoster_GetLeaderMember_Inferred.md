# Review B (skeptical / adversarial): `aa_00574880` ConvoyRoster_GetLeaderMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9F-I dual B) |
| **Counterpart** | `reviews/A_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` |
| **Verdict** | **accept-with-gaps** — body + algebra sealed; product type name open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Hidden logic / multi-path body | Decompiler elision | **Falsified** — 9-ins linear; gate + load only |
| 2 | Stack arg / `ret 4` like GetMemberBySlot | Confuse with twin | **Falsified** — plain `C3`; ECX-only |
| 3 | Base is `this+0x1a` not `0x1a0` | Misread `(i+0x1a)*0x10` | **Falsified** — `add 0x1a; shl 4` |
| 4 | Always returns local player | Invented | **Falsified** — returns slot object*; equality is **caller** side |
| 5 | Writes / mutates roster | Side-effect invent | **Falsified** — load-only |
| 6 | Count at `+0x1d8` is a bool flag only | Over-simplify | **Partial** — zero/non-zero gate here; siblings treat as count |
| 7 | Leader index always 0..3 | Assumed | **Sustained risk** — no body clamp |
| 8 | Same as vehicle `entity+0x1a0` controller holder | Offset collision | **Sustained risk only for wrong type** — convoy roster ≠ VehicleEntity |
| 9 | Product name sealed | Over-promote | **Sustained** — keep `_Inferred` |
| 10 | Dead / unused | Drop from maps | **Falsified** — 10 CALL xrefs |
| 11 | "Leader" is Confirmed product English | ADV residual | **Sustained** — role High/Inferred only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Machine CF + formula | **High** | Wrong port of leader load |
| Count-zero → null | **High** | Miss empty-crew gate |
| Plain `ret` ABI | **High** | Stack imbalance if forced ret 4 |
| Read-only getter | **High** | Fake mutations |
| Result is object ptr at use sites | **High** | Wrong cast |
| `this` = roster at `char+0xcb0` | **High** structure / **Probable** type name | Wrong owner object |
| Leader English | **High** role / **Low** product spelling | Bad NAMING promote |
| Index always valid 0..3 | **Open** | OOB if corrupt |

---

## 3. Cross-check against raw + bytes

```text
// clean ≡ raw ≡ live ≡ machine
// gate +0x1d8; load *(this + (*(this+0x194)+0x1a)*0x10)
void *ConvoyRoster_GetLeaderMember_Inferred(void *roster)
{
  if (*(uint8_t*)((char*)roster + 0x1d8) == 0)
    return 0;
  int slot = *(int*)((char*)roster + 0x194);
  return *(void**)((char*)roster + (slot + 0x1a) * 0x10);
}
```

Hex: `80 b9 d8 01 00 00 00 77 03 33 c0 c3 8b 81 94 01 00 00 83 c0 1a c1 e0 04 8b 04 08 c3`.

---

## 4. Surviving contract for AutoCore

```
ConvoyRoster_GetLeaderMember_Inferred(roster):
  if roster.countByte(+0x1d8) == 0: return null
  slot = roster.leaderIndex(+0x194)   // int; writers keep 0..3
  return roster.slotObject[slot]      // *(roster + 0x1a0 + slot*0x10)

// Do NOT:
//  - add 0..3 clamp without evidence (retail does not)
//  - treat as vehicle controller holder at entity+0x1a0
//  - invent writes / iteration
//  - claim product "GetLeader" demangle Confirmed
//  - force ret 4 (this leaf is plain ret)
```

**Port tests:** empty count → null; non-empty loads leader slot object*; ECX host; no stack cleanup.

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/algebra/call-site leader role; product type English open → **accept-with-gaps**.
