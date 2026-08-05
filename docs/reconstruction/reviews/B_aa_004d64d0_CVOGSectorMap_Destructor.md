# Review B (skeptical / adversarial): `aa_004d64d0` CVOGSectorMap_Destructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d64d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d64d0_CVOGSectorMap_Destructor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is a random HashError helper, not SectorMap dtor | Same vtbl `0x009cc770` as sealed ctor; counter inverse of ctor; Catch deletes object at `+0xe04` after `@@new CVOGSectorMap` path | **Falsified** — class dtor body |
| 2 | `__cdecl` / stack this | `8B F1`; bare `ret` | **Falsified** — thiscall |
| 3 | Returns a value | No EAX publish; pure teardown; `C3` | **void OK** |
| 4 | Raw nested ifs mean early-out skips most frees | `operator_delete` noreturn decompiler artifact; epilogue always reached in sequential free pattern | **Falsified** — sequential model required |
| 5 | Counter is unrelated global | Ctor `_DAT_00b037e4++`; dtor `--`; same VA | **Confirmed** lifecycle pair |
| 6 | Name is PDB symbol `CVOGSectorMap::~CVOGSectorMap` | Class High; method English inferred as Destructor | **Accept as product class + structural dtor** (no `::` string on this VA) |
| 7 | Only Catch means unused | Exception/fail path still real; may also be data-called | **Does not break CF seal** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class + vtbl + ABI | **High** | Wrong host teardown |
| Hash lock/destroy loop | **High** | Leak / double-free |
| Sequential free order | **High** | Port skips subsystems |
| Full field map | **Medium** | Incomplete port of rare slots |
| Product dtor method English | **Medium** | Doc naming only |

---

## 3. Cross-check against raw / bytes

```
raw live:  *this=009cc770; counter--; hash destroy; vdel cascade; PopFront drains; helpers; buffers; ret
bytes:     C7 06 70C79C00; 832D E437B000 01; … 5E5B83C408C3
ctor twin: *this=same vtbl; counter++; size 0xE920; Client_InitInstance
```

Clean must not treat `operator_delete` as noreturn terminating the rest of the dtor.

---

## 4. Surviving contract for AutoCore

```csharp
void CVOGSectorMap_Destructor(CVOGSectorMap map)
{
    // map.Vtbl = SectorMapVtbl;
    // g_sectorMapConstructCount--;
    // Destroy primary hash under traversal lock (FUN_004e3610 path)
    // Virtual-delete owned members in sealed order
    // Drain embedded thread-safe lists (PopFront semantics)
    // Run subsystem dtor helpers matching FUN_004e72xx / FUN_00497360 family
    // Free buffer triples; return
}
```

**Port traps to reject:**

- Skipping counter decrement (refcount/debug mismatch with ctor).
- Modeling decompiler noreturn delete ladder as real control flow.
- Freeing list **nodes** again after PopFront (nodes owned by pop).

---

## 5. Residual gaps (do not block seal)

1. Full 0xE920 English field map.
2. Live/runtime hit verification.
3. Vtbl slot inventory for this body.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break class identity, ABI, or sequential teardown contract. Remaining gaps are field English / runtime, not CF.
