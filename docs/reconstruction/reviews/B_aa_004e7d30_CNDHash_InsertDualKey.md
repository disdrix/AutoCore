# Review B (skeptical / adversarial): `aa_004e7d30` CNDHash_InsertDualKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7d30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-L) |
| **Counterpart** | `reviews/A_aa_004e7d30_CNDHash_InsertDualKey.md` |
| **Scratch** | `tmp/a_004e7d30.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Name is `Named_VOG_DEBUG_STOP` | **Falsified** — string only fires on locked traversal debug; real role is hash insert |
| 2 | Function always inserts | **Falsified** — soft skip (1) and hard fail (E_FAIL) paths |
| 3 | Single 32-bit key | **Falsified** — keyLo + keyHi matched at node +0x18/+0x1c; format string `%u` with two pushes |
| 4 | Multiple callers | **Falsified** — exactly 1 xref (`0x004dc014`) |
| 5 | Lock path aborts insert | **Falsified** — logs then continues into soft/hard/insert logic |
| 6 | `CNDHash_*` product name is retail | **Overstated** — family name from project convention + HashError strings; Ghidra still `FUN_004e7d30` |
| 7 | Alloc size owned here | **Partial** — freelist pop is `FUN_00589890` (slab of 0x28-ish nodes, 10 dwords) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert CF + HRESULT returns | **High** | Broken object hash register |
| Dual key + bucket mask | **High** | Wrong lookup / collisions |
| ABI thiscall + RET 0x10 | **High** | Stack smash |
| Sole caller RegisterObjectHashEntry | **High** | Missed xrefs |
| Soft semantics | **High** CF; **Open** live use | Wrong idempotent path |
| Product type English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
table = ECX
if !value: return E_POINTER
if locked: log HashError + VOG_DEBUG_STOP
if soft and exists(payload): return 1
if exists(payload): log Duplicate; return E_FAIL
node = freelist_pop(table+0x20)
init node; link bucket(keyLo & mask); repair; link DLL; count++; return 0
RET 0x10
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean renames only; CF preserved.

---

## 4. Surviving contract for AutoCore

```
// Object-hash insert (dual TFID/COID key)
hr = CNDHash_InsertDualKey(table, keyLo, keyHi, value, soft=0);
// hr==0 inserted; non-zero → caller deletes allocated descriptor
// node payload at +0xC; keys at +0x18/+0x1c; vtbl PTR_FUN_009cc208
// do not confuse with single-key CNDHash insert clones
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/returns/strings sealed; `VOG_DEBUG_STOP` alias rejected; residual is product English + soft live-use → **accept**.
