# Review B (skeptical / adversarial): `aa_00572360` InventoryGrid_RePlaceItems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-B OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| **System** | inventory-transfer |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI + inventory-family roles; **reject** ShowInventoryFull seed as primary name and any “void / no ret cleanup” claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always returns success | **Falsified** — null related, Place fail, FindFree fail → 0 |
| 2 | No stack cleanup / cdecl | **Falsified** — `ret 8` both exits |
| 3 | `param_2` is only origin Y | **Falsified as ABI** — entry loads it as null-checked pointer; Y reuse is decompiler slot reuse after gate |
| 4 | Primary role is UI “inventory full message” | **Falsified** — callers are SortAndRepack + cargo resize + thin wrapper |
| 5 | Type-4 uses FindFree | **Falsified** — outer `type != 4` skips CanPlace/FindFree |
| 6 | FindFree page is 0 only | **Falsified** — sealed `0xffffffff` at FindFree call |
| 7 | Never touches critical section | **Falsified** — leave CS when `+0x54` on success/fail |
| 8 | Success leaves item RB intact | **Falsified** — free + reinit empty + count 0 |
| 9 | Product name proven | **Fail** — `_Inferred`; does not block accept-with-gaps |
| 10 | Needs `disassemble_bytes` | **Falsified** — decompile + `read_memory` seal ABI/CF |

---

## 2. Decisive evidence

### Entry null gate + ret 8

```text
sub esp,3Ch / push edi
mov edi,[esp+44h]   ; param_2
test edi,edi
mov [esp+4],ecx     ; this
jnz cont
xor al,al / pop edi / add esp,3Ch / ret 8
```

### SortAndRepack call site (`0x00572a4f`)

```text
push ebx            ; flag
push esi            ; related/source
mov  ecx, ebp       ; destination grid
call FUN_00572360
```

Matches dual of SortAndRepack success commit (W20-S residual closed for “null guard” — second arg is real pointer, not literal 0-only).

### Wrapper `FUN_00521e90` bytes

Loads related from `obj+0x250+0x2b0`, sets `ecx` from stack, `push 1; push related; call 00572360` — confirms flag + related ABI.

### Sealed inventory callees

Place / FindFree / CanPlace duals already accept family stamp formula and page `-1` callers including this VA.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ret 8 / 0\|1 | **High** | Broken ports |
| Place/FindFree/CanPlace roles | **High** | Wrong inventory layout |
| Success RB clear CF | **High** | Missed side effect |
| relatedPtr type | **Tentative** | Wrong companion object |
| Empty-RB-after-Place product intent | **Open** | Mis-modeled migrate semantics |
| C++ product name | **Tentative** | Naming only |

---

## 4. What would falsify accept-with-gaps

1. Additional callers with different arity (not ret 8).
2. Proof Place does not run under this body (would contradict sealed call).
3. Image bytes differing on entry null gate.

None observed.

---

## 5. Verdict

**accept-with-gaps.** Prefer `InventoryGrid_RePlaceItems_Inferred` over ShowInventoryFull seed name. Residuals: product symbol, relatedPtr type, success RB-empty intent, runtime golden.
