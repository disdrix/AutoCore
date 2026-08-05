# Review B (skeptical / adversarial): `aa_004f4eb0` Vehicle_DeactivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4eb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f4eb0_Vehicle_DeactivateHardpointWeapons_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` body + call-site bytes. No `disassemble_bytes`. Own VA `0x004f4eb0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function fires all weapons | Callees are clear-to-0 + vfunc(0); fire-all is `0x004f50d0` | **Falsified** — **deactivate/clear**, not fire |
| 2 | Stack args / stdcall | Epilogue plain `C3`; entry only uses ECX | **Falsified** — **thiscall ECX only** |
| 3 | More than 3 hardpoints | Loop bound `cmp esi, 0xC` / `jl` | **Falsified** — **exactly 3** dword slots |
| 4 | Table is inline array at +0x260 | `mov eax,[edi+0x260]; mov ecx,[eax+esi]` | **Falsified as inline** — **pointer to table** |
| 5 | Suppress not cleared | Second call is `FUN_0056b400(0)` sealed dual | **Falsified omission** — both fire + suppress cleared |
| 6 | ECX is character, not vehicle | Call site `mov ecx,[esi+0x250]` then body uses +0x260 hardpoint table | **Partial** — ECX is object at session+0x250 that **owns** hardpoint table (vehicle*); character is the *caller this* |
| 7 | Decompiler CF drifts from bytes | Live decompile ≡ raw; bytes match loop | **Falsified** — no drift |
| 8 | Same as activate sibling | `FUN_004f4f00` uses vfunc(1)/full activate | **Falsified identity** — **deactivate vs activate** twins |
| 9 | Ghidra void/undefined means wrong ABI | Plain ret + ECX this sealed | **Falsified concern** — void is correct |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall vehicle + 0 stack args | **High** | Wrong call convention in port |
| 3-slot +0x260 pointer table | **High** | Miss weapons / OOB |
| Clear order fire then suppress then vfunc(0) | **High** | Residual fire on switch |
| Sole caller vehicle-switch path | **High** | Miss other deactivate sites (none live) |
| vtbl+0x18 product English | **Medium** | Doc-only |
| Runtime bit-exact | **Open** | Shipping switch fidelity |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  for i in 0,4,8:
    w = *(table + i); table = *(vehicle+0x260)
    if w: SetFire(0); SetSuppress(0); vtbl+0x18(0)

bytes:
  56 57 8bf9 33f6 ... 83c604 83fe0c 7cc4 5f5e c3

call site:
  mov ecx, [esi+0x250]
  call 0x004f4eb0
```

**No conflict** among raw, live decompile, and body/call-site bytes on sealed CF.

---

## 4. Surviving contract for AutoCore

- On vehicle switch / inventory handoff, **clear all 3 hardpoint fire+suppress flags** and invoke deactivate vfunc(0) on each live weapon pointer under `vehicle+0x260`.
- Do not implement as fire-all or as a single-weapon helper.
- Server AutoCore may omit presentation vfunc but should clear authoritative fire-intent state when mirroring switch.

**Verdict:** **accept-with-gaps**
