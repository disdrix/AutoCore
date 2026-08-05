# Review B (skeptical / adversarial): `aa_00458510` StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00458510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-K) |
| **Counterpart** | `reviews/A_aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is ECX-thiscall with `ret 8` like `004a7580` | **Falsified** — **EAX** map, **EBX** value*, **`ret 4`** |
| 2 | Signed int key compare | **Falsified** — **unsigned** `SETB` / `JAE` |
| 3 | Val12 isnil@+0x19 | **Falsified** — isnil **@+0x15** (Val8 family) |
| 4 | Hit updates mapped value | **Falsified** — equal path stores `inserted=0` only |
| 5 | Palantir product member | **Narrow** — generic map helper; FourCC wrappers are callers |
| 6 | Decompiler void/no-arg prototype is truth | **Falsified** — phantom EAX/EBX + stack out sealed by bytes |
| 7 | Always inserts (no uniqueness) | **Falsified** — equal returns existing node |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI ret 4 | **High** | stack smash / wrong map |
| Unsigned key | **High** | sort order bugs |
| Equal-no-write | **High** | silent value clobber |
| isnil15 vs isnil19 mix-up | **High** | corrupt tree |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
EDI = EAX map; EBP = out; EBX = value*
walk isnil@+0x15; goLeft = key < node.key (unsigned SETB)
if goLeft && node==leftmost: insert(1) → out{it,1}; ret 4
if goLeft: predecessor(004129f0)
if node.key < key (unsigned): insert(goLeft) → out{it,1}; ret 4
else: out{node,0}; ret 4
```

Clean must **not** use thiscall/`ret 8` peer template or signed compares from `004a7580` / Val12 peers.

---

## 4. Surviving contract for AutoCore

```csharp
// Unique insert-or-find; register ABI
// map in "this-like" register (EAX), value* in EBX, out on stack
(InsertPair out) InsertOrFind(MapShell map, in Val8 value)
{
    // lower_bound style walk with UNSIGNED key at value.Key / node+0x0C
    // isnil at +0x15
    if (/* miss */) { var n = InsertAndRebalance(...); return (n, true); }
    return (existing, false); // do NOT rewrite existing.Mapped
}
```

Server ports must preserve **unsigned** order and **no hit rewrite**.

---

## 5. Open questions

1. Exact demangled map types for six callers.  
2. Whether insert helper rewrites value on internal paths (parent here never rewrites on hit).  
3. Predecessor helper dual (`FUN_004129f0`) — unOWN.
