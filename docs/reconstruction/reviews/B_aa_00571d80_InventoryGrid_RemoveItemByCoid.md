# Review B (skeptical / adversarial): `aa_00571d80` InventoryGrid_RemoveItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571d80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00571d80_InventoryGrid_RemoveItemByCoid.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (WQ8R-D) |
| **Verdict** | **accept** on CF/ABI/rel32; **reject** overclaims of void return, free calling convention, or that removeQty is a formal |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is void | **Falsified** — EAX from RemoveItem returned; callers `test` result |
| 2 | stdcall/cdecl without this | **Falsified** — `MOV ESI, ECX`; both callees use ESI as this |
| 3 | Three formals include removeQty | **Falsified** — only coidLo/coidHi/forceFull; qty is imm `1` |
| 4 | Calls FindByCbid (`0x005710c0`) | **Falsified** — rel32 lands `0x00571010` (COID) |
| 5 | Always fully removes stack | **Falsified** — forceFull=0 + peel path inside Remove leaves partial |
| 6 | Null Find crashes | **Falsified** — Remove null-gates at entry |
| 7 | `ret 8` (two args) | **Falsified** — `C2 0C 00` = ret 12 |
| 8 | Ready for bit-exact complete | **Fail** — runtime/diff open |
| 9 | Scaffold FUN clean is finished quality | **Falsified** — named clean is authoritative |

---

## 2. Decisive dataflow (bytes + decompile 2026-08-04)

```
grid = ECX
coidLo = [esp+4]; coidHi = [esp+8]; force = [esp+0xC]
item = FindItemByCoid(grid, coidLo, coidHi)   // 0x00571010, ret 8
return RemoveItem(grid, item, 1, force)       // 0x00571b80, ret 0xC
// RET 0x0C
```

### Byte attack

| Attack | Bytes | Result |
|--------|-------|--------|
| this lost? | `MOV ESI,ECX` then both `MOV ECX,ESI` | **preserved** |
| qty formal? | only one `6A 01` imm | **not a formal** |
| Find is CBID? | rel32 `E8 75 F2 FF FF` → `00571010` | **COID** |
| Remove wrong? | rel32 `E8 DD FD FF FF` → `00571b80` | **RemoveItem** |
| ret 8? | `C2 0C 00` | **ret 12** |

Live decompile matches raw CF; understates return type and thiscall.

---

## 3. Confidence table (adversarial)

| Dimension | Level | Note |
|---|---|---|
| Boundary / size | **Confirmed** | 39 B |
| ABI thiscall + ret 0xC | **Confirmed** | |
| Callee identity | **Confirmed** | rel32 |
| qty=1 | **Confirmed** | |
| Return value | **High** | callers check EAX |
| forceFull product meaning | Probable | site-dependent |
| Runtime | Open | |

---

## 4. Residual attacks (open, non-blocking)

1. Does any site pass forceFull outside {0,1}? (sell uses `pkt+0x2c != 0` bool-like.)  
2. Double-call pattern in `FUN_00810170` (two force=1 attempts) — same grid twice; second may be alternate inventory? (caller residual, not this body.)  
3. PDB name.

---

## 5. Verdict

**accept** — no surviving attack on the sealed wrapper formula. Reject only overclaims listed above.
