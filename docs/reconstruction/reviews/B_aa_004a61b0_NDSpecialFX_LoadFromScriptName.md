# Review B (skeptical / adversarial): `aa_004a61b0` NDSpecialFX_LoadFromScriptName

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a61b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` |
| **Verdict** | **accept-with-gaps** on path/open/parse CF; **needs-more-evidence** on success return/ownership |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Appends bare `".xml"` | **Falsified** — `read_memory(0x009ca184)` = `_nfx.xml` |
| 2 | Path uses POSIX `../scripts/` | **Falsified** — bytes are `..\scripts\` |
| 3 | Function always returns null | **Rejected as behavioral truth** — 39 callers store/check non-null; decompiler noreturn on `operator_delete` explains false null |
| 4 | `flags` selects load mode | **Falsified for this VA** — no body/pcode use; still passed by callers (0/2/4/−1) |
| 5 | `unused` is dead | **Partially falsified** — forwarded to `FUN_004a0b90` as arg5 (particle/instance stamp) |
| 6 | Success deletes the only FX object then returns it | **Unstable** — if true, callers would UAF; more likely clone-then-free-template **or** epilogue mis-decompile |
| 7 | `FUN_004a0b90` is optional polish | **Falsified** — always invoked when parse non-null; creates 0x240-class runtime graph from template |
| 8 | Finished exact / bit-for-bit | **Overstated** — success return residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Path prefix + `_nfx.xml` rule | **High** | Wrong file, missing interact/weather FX |
| Open tag `NDSpecialFX` | **High** | Open fails always |
| Parse first node only | **High** | Multi-root scripts ignored |
| `flags` ignored here | **High** | Port might over-implement unused arg |
| Success returns live FX* | **High (caller contract)** / **Low (decompiler)** | Interact icons / weather / elite attach null |
| Delete-template vs return-clone | **Low** | Leak or double-free in port |
| `FUN_004b99c0` is full FX dtor | **Medium** | Wrong free order |

---

## 3. Cross-check against raw

```
raw/clean:
  path build + OpenTaggedDocument + first node + FUN_004a4fa0
  + FUN_004a0b90(fx, fx+0xd5, 1, -1, unused)
  + FUN_004b85d0; FUN_004b99c0; operator_delete(fx)
  + always return 0

adversarial:
  path/open/parse ≡ raw  (accept)
  always-return-0      ≠ caller contract (gap)
  plate ".xml"         ≠ memory "_nfx.xml" (correct plate)
```

Pcode fail BB sets `EAX=0` before ret — **failure null is real**. Success BB ends at `operator_delete` modeled noreturn — **success return not recovered**.

---

## 4. Surviving contract for AutoCore

```
NDSpecialFX_LoadFromScriptName(name, flags /*unused*/, stamp):
  path = "..\\scripts\\" + name
  if "_nfx.xml" not in name: path += "_nfx.xml"
  doc = OpenTaggedDocument(path, "NDSpecialFX")
  if open ok and has node:
    node = first_node(0)
    if !node: log VOG_DEBUG_STOP
    else:
      fx = ParseSpecialFX(node, out_eventType, out_counter, name)
      Release(node)
      if fx:
        InstantiateFromTemplate(fx, fx+0xD5, mult=1, filter=-1, stamp)
        // RETURN: live FX*  — DO NOT trust decompiler null
        // ownership of template vs instance: OPEN
  return null on any failure
```

**Port guidance:** client-only script load. Do not depend on `flags` until another VA consumes it. Prefer returning the object callers attach (interact FX, weather slot, elite vtbl+0xf8, skill FX).

---

## 5. Attack scenarios that must not pass review

1. **Modernize to always append `.xml`** — breaks `_nfx.xml` convention and double-suffix if names already include it.
2. **Treat always-null as intentional** — would “prove” all interact icons fail; contradicts production client.
3. **Drop `FUN_004a0b90`** — leaves template without instance graph (particles/geometry not activated).
4. **Implement `flags` as file cache policy without evidence** — invents behavior outside this VA.

---

## 6. Open questions

1. Recover success epilogue: does `004a0b90` return instance in EAX, and is `pvVar4` template freed?
2. Exact type at `fx+0xd5` (name buffer vs sub-object).
3. Why callers pass `flags` if this VA ignores them (API symmetry? other build?).
4. Relation of `local_12c` to `NDXml_OpenTaggedDocument` out-params / session object from `FUN_00799940`.

**Verdict:** **accept-with-gaps** on path/open/parse CF; **needs-more-evidence** on success return/ownership before claiming exact clean.
