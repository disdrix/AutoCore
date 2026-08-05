# Review B (skeptical / adversarial): `aa_004ce5f0` Character_HostModeGateForObjectV210

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-F) |
| **Counterpart** | `reviews/A_aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims). No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | ConfirmEquip-only helper (parent-seed sole role) | **Falsified** — equip type 0xe/0x10, hardpoint drop ×2, confirm UI |
| 2 | Bare `ret` / no stack cleanup | **Falsified** — `c2 04 00` |
| 3 | Body implements equip / mutates inventory | **Falsified** — pure predicate; no stores |
| 4 | Host flags equal world/continent same offsets by product name | **Unfounded** — offsets sealed; English transfer not proven |
| 5 | vcall is host `vtbl+0x210` | **Falsified** — vcall is on **object** MI-this |
| 6 | Arg to vcall is `(0,1)` like TryEquipItem host precheck | **Falsified** — body pushes single **0** |
| 7 | Returning false means “broken item” | **Falsified** — callers map false → status **1** (not Broken=9) |
| 8 | Non-leaf with external CALLs | **Falsified** — classification leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predicate CF + ABI | **High** | inventing equip side effects |
| Object vcall (not host) | **High** | wrong port target |
| Flag offsets | **High** | wrong gate polarity |
| Flag English / town-vs-sim labels | **Low–Open** | docs reuse other `+0xf5` meanings without proof |
| Structural name | **High** as structural | over-claiming product name |

---

## 3. Cross-check against raw + bytes

```
Character_HostModeGateForObjectV210:  ; ECX=host, [esp+4]=object, ret 4
  test object; jz false
  MI-adjust object; call [vtbl+0x210](0)
  test eax; jz false
  if host[+0xf5] return true
  return host[+0x7e] != 0
```

Any clean plate that stores equip flags, calls loaders, or omits stack cleanup is **wrong** for this VA.

---

## 4. Surviving contract for AutoCore

```c
// Port as pure gate — do not invent equip side effects here
bool Character_HostModeGateForObjectV210(Host* host, Object* obj);

// Callers (vehicle equip): if (!gate) return 1;
// Do not confuse with Broken (code 9) or session +0xf6 checks in TryEquipItem.
// Host +0xf5 / +0x7e product English remains open — preserve offsets only.
```

---

## 5. Open questions

1. PDB / product symbol.
2. Host flag English on character layout.
3. Object vfunc+0x210(0) return type / product role.
4. Runtime / differential.

**Verdict:** **accept-with-gaps**
