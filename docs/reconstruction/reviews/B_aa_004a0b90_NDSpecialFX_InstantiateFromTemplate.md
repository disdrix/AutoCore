# Review B (skeptical / adversarial): `aa_004a0b90` NDSpecialFX_InstantiateFromTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a0b90` |
| **VA** | `0x004a0b90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004a0b90_NDSpecialFX_InstantiateFromTemplate.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA); parent dual residual only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is a shallow `memcpy` of the host | Multiple `operator_new` + list walks + specialized ctors | **Falsified** — deep multi-structure instantiate |
| 2 | Always clones every child | Filter `param_4`; skip unless `id == filter` or filter `== -1` | **Falsified as always** — filtered |
| 3 | Scale 0 still spawns one | Loops are `for i < count*scale` / `while count--`; scale 0 → no body | **Falsified** — zero scale skips |
| 4 | `param_2` must be `template+0xd5` | Ctor takes any `char*`; loader happens to pass `+0xd5` | **Over-constrained** — often but not forced by this VA |
| 5 | Returns the new host in EAX | Decompiler `void`; epilogue is temp-list dtor; no sealed `mov eax, iVar3` in this review | **Unproven** — **major residual** |
| 6 | Loader “delete template then use return” is settled | Parent dual already flags success return broken | **Shared open** — do not claim sealed ownership |
| 7 | `+0x204` start index always 0 | When `flags90d & 1`, start = `count*scale - 1` (single last slot) | **Falsified as always 0** |
| 8 | `+0x1e0` count always from `+0x8f8` | If `node+8 != 0`, count from `*(short*)(*(node+8)+700)` | **Falsified as always +0x8f8** |
| 9 | Map walk at `+0x228` clones into clone host map | `FUN_004a7580(&local_40,…)` — local map/sentinel, not obviously `iVar3+0x228` | **Risk** — may be side map; residual binding |
| 10 | Null `new` is safe | `iVar3=0` then immediate `*(iVar3+0x28)=…` | **Falsified** — null deref on OOM |
| 11 | Name `NDSpecialFX_*` is string-proven in this VA | No NDSpecialFX string in body; inferred from caller/ctor | **Inferred only** |
| 12 | Scaffold clean is rehost-ready | Still `FUN_*`, SEH, `void` return, raw list plumbing | **Scaffold for CF** only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Deep clone multi-list CF | **High** | Missing child types on port |
| Scale × short count | **High** | Wrong instance multiplicity |
| Filter −1 vs id match | **High** | Wrong subset instantiate |
| Stamp field stores | **High** | Lifetime/id bugs on instances |
| Host size 0x240 / ctor | **High** | Heap overflow / wrong type |
| Return/ownership | **Low** | Use-after-free / leaked hosts |
| `+0x228` destination map | **Medium** | Silent drop of map entries |
| Product type names | **Low** | Mis-named server/client ports |
| OOM path | **Low safety** | Crash |

---

## 3. Cross-check against raw / clean

```
NDSpecialFX_InstantiateFromTemplate(template, name, scale, filter, stamp):
  host = new(0x240); if host: FUN_004ba310(host, name)
  copy flags ( +0x28, +0xc, +7, +6, +4 )
  if filter == -1: FUN_004a7e30(template+0x90)
  optional blob+0x60 copy (0x30) with backlink
  walk template maps/lists:
    +0x228 map payloads 0x28
    +0x204 scaled filtered spawns (FUN_00590800) stamp[0x242]
    +0x21c sidepath
    +0x1e0 deep graph (FUN_005bdcf0) stamp+0x8c4, parent host
    +0x210 scaled 0x17c (FUN_005b94e0) stamp
    +0x1ec POD 0x138
    +0x1f8 POD 200
  destroy temps
  // return host? UNSEALED
```

Raw ≡ live decompile. Clean matches CF/immediates. Annotated documents offsets and caller seal.

Prologue seal: `push 0x240; call operator_new` after SEH setup.

---

## 4. Surviving contract for AutoCore

```
When loading/instancing NDSpecialFX templates:

  - Host object size is 0x240; construct with name string (often
    embedded at template+0xd5, capacity 0x104).
  - Instantiation is NOT a byte-wise memcpy: child lists are
    re-allocated and linked; primary graph nodes rewire parents.
  - Per-entry short counts scale by an integer multiplier
    (loader uses 1).
  - Optional filter id selects a subset; -1 clones all.
  - Stamp integer is copied onto spawned instances for later
    identity/lifecycle (exact schema residual).
  - Do not assume decompiler void-return means "no host":
    ownership is an OPEN residual shared with LoadFromScriptName.
  - OOM is not handled; retail assumes new succeeds.

Ports that only shallow-copy the 0x240 header will miss FX
children (particles, attachments, audio hooks).
```

---

## 5. Open questions

1. Where the clone host is published (return EAX vs global FX manager).
2. Whether loader `operator_delete(template)` is real or decompiler mis-model (parent dual residual).
3. Binding of `FUN_004a7580` inserts (which map root).
4. Product names for child structs (`0x3e4`, `0x17c`, `0x138`, `200`).
5. Runtime differential / heap tracing not run.
6. SEH exception paths if mid-clone throws.

**Verdict:** **accept-with-gaps**
