# Review B (skeptical / adversarial): `aa_005405e0` Client_IsRequirementEventActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_005405e0` |
| **VA** | `0x005405e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005405e0_Client_IsRequirementEventActive.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** on CF/ABI/membership; **reject** listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `__thiscall` / character this | **Falsified** — free function; no ECX this; cdecl `ADD ESP,4` at sole site |
| 2 | Binary search / hash lookup | **Falsified** — **linear** scan, stride 4 |
| 3 | Returns full pointer / node | **Falsified** — **`AL` 0/1 only** |
| 4 | Decompiler `CONCAT31` / high EAX bits are semantic | **Falsified** — live `MOV AL,1` / `XOR AL,AL` |
| 5 | Empty range returns non-zero garbage | **Falsified as behavior** — empty hits `XOR AL,AL`; decompiler mask form is noise |
| 6 | Multiple callers across systems | **Falsified** — **sole** xref = `CheckMissionRequirements` |
| 7 | Mutates / registers events | **Falsified** — read-only scan |
| 8 | Arg is mission id / objective id | **Falsified for site** — mission def **`+0x118` RequirementEventId** |
| 9 | Skip condition is `0` not `-1` | **Falsified** — caller `CMP EAX,-1` / `JZ skip` |
| 10 | Product name proven | **Unproven** — role sealed only |
| 11 | Global bounds are length/capacity not iterators | **Falsified** — used as **begin/end pointers** (`CMP EAX,ECX`, `ADD EAX,4`) |
| 12 | Bit-exact / runtime complete | **Fail** — static dual only |

---

## 2. Decisive dataflow (raw + live)

```
p = *DAT_00b04718
end = *DAT_00b0471c
if p == end: return 0
id = stack0
while p != end:
  if *p == id: return 1
  p++
return 0
```

Live decompile CF **≡** raw. Assembly **beats** decompiler return encoding. Sole call site seals cdecl + RequirementEventId argument + hard-fail on false.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Linear membership 0/1 | **High** | Wrong event gate → auto-grant spam or block |
| cdecl one stack arg | **High** | Stack misalignment |
| Globals begin/end iterators | **High** | Wrong table interpretation |
| Sole caller Requirements | **High** | Missed side path (none static) |
| `+0x118` = RequirementEventId | **High** | Wrong mission field |
| Who fills the vector | **Open** | Stale/empty events → permanent fail/pass |
| Product English | **Open** | Naming only |
| Runtime / differential | **Open** | Residual parity |

---

## 4. Offset / ABI attack checklist

| Check | Result |
|---|---|
| No this in ECX required | **Pass** |
| Stack arg at `[ESP+4]` | **Pass** |
| Bare `RET` (not `RET 4`) | **Pass** (`c3`) |
| Found path `MOV AL,1` | **Pass** |
| Miss path `XOR AL,AL` | **Pass** |
| Stride 4 | **Pass** (`83 c0 04`) |
| DAT begin `0x00b04718` / end `0x00b0471c` | **Pass** (absolute loads) |
| Caller cleanup `ADD ESP,4` | **Pass** @ `0x00546399` |

---

## 5. What would overturn this dual

1. New xrefs after image change (second caller with different ABI).
2. Proof globals are not an active-id vector (e.g. struct array with different stride) — would need body change; current body is dword compare.
3. Proof Requirements passes a field other than `+0x118` (site contradicts).
4. Writer dual showing different semantic (name refinement only unless element meaning changes).

Until then, membership CF + sole-caller ABI stand at **High**.
