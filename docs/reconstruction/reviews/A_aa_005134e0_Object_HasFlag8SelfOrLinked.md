# Review A (reconstruction fidelity): `aa_005134e0` Object_HasFlag8SelfOrLinked

| Field | Value |
|---|---|
| **Stable ID** | `aa_005134e0` |
| **VA** | `0x005134e0` |
| **Canonical name** | `Object_HasFlag8SelfOrLinked` (proposed; was `FUN_005134e0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_005134e0_Object_HasFlag8SelfOrLinked.md` |
| **System** | targeting / object-flags |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** — **mask `0x08` @ `+0x184` sealed** |

---

## 1. Purpose

**Link-aware boolean predicate.** Returns true if the object has flag mask **`0x08`** (bit **3**) at **`obj+0x184`**, or — when a parent link at **`obj+0xac`** exists — if a related/parent object also carries the same logical flag. Callers treat true as **exclude / reject / remove** (skill gather `filterB`, targeting HB, AI target pick, contact countdown).

**Calling convention (bytes):** `this` / object in **ECX**; **no** stack args; bool in **AL**; **`ret`** (`c3`).

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `param_1` (ECX) | `Object*` | `mov esi,ecx`; loads `+0xac` / `+0x184` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005134e0_FUN_005134e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005134e0_FUN_005134e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_HasFlag8SelfOrLinked.cpp` |
| Function record | `docs/reconstruction/functions/aa_005134e0_FUN_005134e0.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x005134e0` — **≡ raw body** |
| Live bytes | Ghidra `read_memory` 128 B @ `0x005134e0` — ends `c3` + `CC` |
| Function bounds | `get_function_by_address` → body `005134e0`–`00513540` |
| Callers sample | `get_function_callers` (AI, skill gather helper, targeting HB, contact, UI) |
| Peer dual | `A_aa_00604dd0_CVOGHBTargeting_OnHeartBeat` cites this predicate |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff, full product naming of flag.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Load parent `@obj+0xac` | **Yes** (`8b 8e ac 00 00 00`) |
| Null parent → self-only `+0x184 & 8` | **Yes** |
| Non-null → `call [vtbl+0x19c]` on parent | **Yes** (`ff 90 9c 01 00 00`) |
| Self bit via `test [esi+0x184], 8` | **Yes** (`b2 08` + `84 96 84 01 00 00`) |
| Related non-null → MI `+0x188` bit | **Yes** (`84 94 06 88 01 00 00`) |
| Related null → parent `+0x184` bit OR self | **Yes** |
| Bool return in AL | **Yes** (`seta` / `sbb+neg`) |

### Closed form (sealed)

```text
// ECX = Object*
if (*(obj+0xac) == 0)
  return (*(obj+0x184) & 8) != 0;

related = (*(obj+0xac))->vtbl[+0x19c]();
self = (*(obj+0x184) & 8) != 0;
if (related != 0)
  return self || ((related + *(*(related+4)+4) + 0x188) & 8) != 0;
return self || ((*(obj+0xac) + 0x184) & 8) != 0;
```

### Mask **`0x08`** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `& 8` on all three flag loads |
| Bytes | `b2 08` (`mov dl,8`); leaf `24 08` (`and al,8`) |
| Bit index | **3** (`1<<3`); not bit index 8 |
| Offsets | self/parent `+0x184`; related MI `+0x188` |

---

## 4. Caller roles (context, not owned)

| Caller class | Use of return |
|--------------|---------------|
| `FUN_0058a810` (skill pair-accept) | if `filterB==0` and this ≠0 → **reject** |
| `FUN_00604dd0` targeting HB | if true on owner → `vtbl+0x18(1,1)` remove-style |
| AI FindTarget / GetAggro | gate candidate |
| Contact countdown / UI interact | various skip paths |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary (`005134e0`–`00513540`, `ret`) | **High / Sealed** |
| ECX = object; no stack args | **High / Sealed** |
| Mask **`0x08`** bit 3 @ `+0x184` | **High / Sealed** |
| Link-aware OR via `+0xac` / vtbl `+0x19c` | **High / Sealed** |
| Role = exclude predicate when true | **High** (caller CF; no string in unit) |
| Product English of flag | **Open** |
| Original PDB symbol | Open |

---

## 6. Verdict

**Accept-with-gaps.** Live body matches raw; bytes seal mask **`0x08`**, offsets, and three-path OR. Product flag name and related virtual name remain open.
