# Review B (skeptical / adversarial): `aa_005021d0` Vehicle_ApplyHardpointFireMask_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005021d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005021d0_Vehicle_ApplyHardpointFireMask_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` entry/mid/epilogue + xrefs. No `disassemble_bytes`. Own VA `0x005021d0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is AI-only | Also `VehicleNet_ReconcilePrediction` ×2 | **Falsified exclusivity** — AI **and** net |
| 2 | `+0x260` is stabilizer-only table | Same table as `Weapon_SetFireFlagPair` / fire-all duals | **Falsified** — **hardpoint weapons** |
| 3 | Always starts fire when bit set | Gates: +0xCB, world+0x7E, vtbl+0x4C canFire | **Falsified** as unconditional |
| 4 | Else branch never runs with want=true | When +0xCB or world gate fails, else still `SetFireFlagPair(true)` | **Confirmed hazard** — flags can latch without HB |
| 5 | Loop is 4 weapons | `i < 3`; AI mask bits 1/2/4 only | **Falsified** — **3** slots |
| 6 | `FUN_0056d160` this is global DAT | Parent dual: FireHelper is weapon thiscall; entry bytes reload weapon into ECX before call | **Partial** — decomp display **suspect**; role still fire-helper |
| 7 | No UI side effects | Opcode **0x31** + slot when local player matches | **Falsified** as pure sim |
| 8 | Alloc size free / wrong HB type | `operator_new(0x24)` + `FUN_005fe6a0` dual = weapon-fire HB type 9 | **Falsified** as generic |
| 9 | Void / wrong stack arity | Epilogue **`C2 04 00`** | **Falsified concern** — one stack arg sealed |
| 10 | Three-rep diverges | live decomp ≡ raw; bytes support SEH + RET 4 + 3-loop | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall vehicle + mask + RET 4 | **High** | Wrong ABI |
| 3-slot +0x260 walk | **High** | Miss rear/front fire |
| Fire path gates + HB enqueue | **High** | Silent no-fire / leak |
| SetFireFlagPair dual args | **High** | Sticky fire flags |
| Callers AI + net | **High** | Incomplete port |
| LogicUi 0x31 English | **Medium** | UI-only |
| FireHelper this formal | **Medium** | Wrong ECX on port |
| 1000 period formal | **Medium** | Timer wrong |
| Runtime / bit-exact | **Open** | Combat fidelity |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for i in 0..2:
    weapon = veh+0x260[i]
    if !weapon: continue
    want = mask & (1<<i)
    if want && weapon+0xCB==0 && world+0x7E:
      can = weapon.vtbl+0x4C(0)
      SetFireFlagPair(can)
      if can: FireHelper; maybe UI 0x31; new HB; enqueue; Start
    else:
      SetFireFlagPair(want)

bytes (selected):
  entry SEH + sub esp,0x144 + mov esi,ecx
  cmp i,3 / jl loop
  push 0x24; operator_new
  push 1000; ctor path
  opcode imm 0x31 before Client_SendLogicUiPacket
  epilogue: ret 4
```

**No CF conflict** on sealed stages. Residual is naming/English and FireHelper this display.

---

## 4. Surviving contract for AutoCore

```csharp
// Vehicle_ApplyHardpointFireMask_Inferred @ 0x005021d0
// this = vehicle*; stack: byte fireMask (bits 0..2); RET 4

void ApplyHardpointFireMask(Vehicle v, byte mask)
{
    for (int i = 0; i < 3; i++)
    {
        var w = v.Hardpoints[i]; // +0x260
        if (w == null) continue;
        bool want = (mask & (1 << i)) != 0;
        if (want && w.ByteCB == 0 && v.World.Flag7E != 0)
        {
            bool can = w.CanFireVfunc(0); // vtbl+0x4C
            Weapon_SetFireFlagPair(w, can);
            if (can)
            {
                Weapon_FireHelper(w, /*suppress*/ 0);
                if (IsLocalPlayer(v))
                    Client_SendLogicUiPacket(opcode: 0x31, slot: i);
                var hb = new CVOGHBWeaponFire(w /*, period 1000 */);
                WorldHbList.Enqueue(hb); // world+0xE4EC
                hb.Start();
            }
        }
        else
        {
            Weapon_SetFireFlagPair(w, want);
        }
    }
}
```

Port notes:
- Parent AI builds mask from geometry; always calls even when mask=0 (clears).
- Net reconcile can push independent masks — do not assume AI-only.
- `+0xCB` gate pairs with `FUN_0056b400` latch from ctor path (sibling).

---

## 5. Verdict

**accept-with-gaps** — adversarial pass confirms shared hardpoint fire applicator for AI and net; residual decompiler this-swap on FireHelper and UI opcode English only.
