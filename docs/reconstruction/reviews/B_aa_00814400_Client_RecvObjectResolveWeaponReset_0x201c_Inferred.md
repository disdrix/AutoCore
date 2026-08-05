# Review B (skeptical / adversarial): `aa_00814400` Client_RecvObjectResolveWeaponReset_0x201c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00814400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` body + parent dispatch decompile. No `disassemble_bytes`. Own VA `0x00814400` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Handler **fires** the weapon | FireHelper called with **param_3=1**; sealed FireHelper dual: param_3≠0 early-return suppress path | **Falsified as fire emit** — **suppress/reset** |
| 2 | Clean cdecl with stack packet* | Body uses **EDI/EBX** unaff; parent switch only `FUN_00814400()` | **Falsified** — **dispatch-custom regs** |
| 3 | Always creates new object | Branch: resolve hit → update path, not create | **Falsified** — **create only on miss** |
| 4 | Always touches weapon | Null object or null `vtbl+0x1E0` skips weapon block | **Falsified** — **conditional** |
| 5 | Same as 0x201A sibling | `FUN_00814470` has no fire-helper tail | **Falsified identity** — 0x201C unique weapon reset |
| 6 | Opcode is 0x2018/0x2019/0x201A | Parent case label **0x201C** only xref | **Falsified** — sealed **0x201C** |
| 7 | Decompiler invents ResolveObjectTarget | Relative call from bytes → `0x004bae70` named plate | **Falsified invention** — real callee |
| 8 | `FUN_00811e00` takes only EBX | Bytes: `push ebx; mov ecx,edi; call` + object in EAX | **Partial Ghidra display** — **packet this + game stack + in_EAX object** (nested not OWN) |
| 9 | Three-rep / raw drift | Live decompile ≡ raw scaffold | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode 0x201C sole entry | **High** | Wrong wire routing |
| EDI packet / EBX game | **High** | Corrupt resolve/create |
| Resolve field offsets | **High** | Wrong object identity |
| Suppress FireHelper not fire emit | **High** | Spurious client shots |
| Nested create/update full semantics | **Medium** | Incomplete spawn port (not OWN) |
| Product English / DAT_00d1a680 | **Open** | Doc-only |
| Runtime differential | **Open** | Shipping fidelity |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  resolve(packet+0x98/90/94)
  null? create : update
  if obj: w=vtbl+0x1e0(); if w: SetFire(0); FireHelper(&DAT_00d1a680,1)

bytes:
  8a97... 8b87... 8b8f... 8b8b340d0000 e8...  ; resolve
  740a ... e8... eb09 5753 e8...               ; update vs create
  ff90e0010000 6a00 e8... 6a01 6880a6d100 e8... ; weapon tail
  5ec3

parent:
  case 0x201c: FUN_00814400(); return 1;
```

**No conflict** on sealed CF among raw, live decompile, and bytes. Nested helper full CF is out of ownership.

---

## 4. Surviving contract for AutoCore

- Wire **0x201C** → resolve object by TFID/type; create if missing; update if present.
- After object exists, if a weapon is exposed via getter slot **0x1E0**, **clear fire flags** and run fire-helper in **suppress** mode (do not treat as shoot command).
- Preserve custom dispatch register contract if rehosting client handlers.

**Verdict:** **accept-with-gaps**
