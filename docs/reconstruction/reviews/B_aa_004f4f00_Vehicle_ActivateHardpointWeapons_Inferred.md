# Review B (skeptical / adversarial): `aa_004f4f00` Vehicle_ActivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4f00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-E) |
| **Counterpart** | `reviews/A_aa_004f4f00_Vehicle_ActivateHardpointWeapons_Inferred.md` |
| **Scratch** | `tmp/a_004f4f00.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the **deactivate** helper (`004f4eb0`) | **Falsified** — no `0056b400`; activate arg is **1** not 0; has full vtbl[0] path |
| 2 | Walks more/fewer than 3 slots | **Falsified** — bound `i < 0xC`, step 4 |
| 3 | Stack formals / `ret N` | **Falsified** — bare `ret` after local `add esp,0x10` |
| 4 | Clears suppress flag | **Falsified** — only `0056a260(0)` |
| 5 | Multiple callers | **Falsified** — sole xref from `005252f0` @ `005259ad` |
| 6 | Table at wrong offset | **Falsified** — `[this+0x260]` matches weapon hardpoint duals / deactivate twin |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Activate vs deactivate polarity | **High** | Weapons stuck off/on after switch |
| 3-slot +0x260 | **High** | Miss hardpoints / OOB |
| ABI thiscall 0-arg | **High** | Stack smash on port |
| +0x08 branch semantics | **Medium** | Wrong activate path |

---

## 3. Cross-check against raw + bytes

```
for off in {0,4,8}:
  w = table[off]
  if !w: continue
  SetFireFlagPair(w, 0)
  if w[+8]==0: vtbl[0](1, 0.., g_flOne, 0)
  else:         vtbl+0x18(1)
ret
```

Clean must **not** invent suppress clear, deactivate(0), or 4th hardpoint slot.

---

## 4. Surviving contract for AutoCore

```c
// Port of Vehicle_ActivateHardpointWeapons (client vehicle+0x260)
// thiscall Vehicle*; 0 stack args
void Vehicle_ActivateHardpointWeapons(Vehicle* v) {
  auto* table = *(Weapon***)( (uint8_t*)v + 0x260 );
  for (int i = 0; i < 3; ++i) {
    Weapon* w = table[i];
    if (!w) continue;
    Weapon_SetFireFlagPair(w, 0);
    if (*(uint32_t*)((uint8_t*)w + 8) == 0)
      FullActivate(w, /*active*/1, /*scale*/1.0f);
    else
      ShortActivate(w, 1); // vtbl+0x18
  }
}
```

---

## 5. Gaps that survive adversarial pass

1. Product/PDB symbol.
2. Exact meaning of `weapon+0x08` gate.
3. Whether call-site vehicle at `character+0x250` is already rebound to new chassis.
4. Runtime / bit-exact.

**Verdict:** Adversarial pass **confirms** A on polarity/ABI/slots → **accept-with-gaps**.
