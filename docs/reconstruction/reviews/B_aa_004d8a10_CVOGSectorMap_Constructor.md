# Review B (skeptical / adversarial): `aa_004d8a10` CVOGSectorMap_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d8a10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-F) |
| **Counterpart** | `reviews/A_aa_004d8a10_CVOGSectorMap_Constructor.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs/caller string for role). No `disassemble_bytes`. Own VA `0x004d8a10` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__cdecl` free function | `mov esi,ecx`; bare `ret` | **Falsified** — **thiscall ctor** |
| 2 | Returns void / HRESULT | `mov eax,esi` | **Falsified** — **returns this*** |
| 3 | Small helper | body ~0x97F B; alloc 0xE920 | **Falsified** — **large object ctor** |
| 4 | Name only via parent-seed | `@@new CVOGSectorMap` in InitInstance | **Falsified incompleteness** — **product class High** |
| 5 | No global publish | `_DAT_00b03600 = param_1` | **Falsified** — **singleton-ish install** |
| 6 | Tree inits invent new logic here | bodies are `FUN_004e7450`/`7420` calls | **Falsified** — **delegates to sealed helpers** |
| 7 | Clean field names are PDB-proven | no per-field strings in body | **Open English** for most offsets |
| 8 | Clean helpers change store order | phased rewrite must match raw order | **Watch** — port from **raw** if exact order matters |
| 9 | Three-rep diverges | live ≡ prior raw ≡ entry/tail bytes | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + return this + bare ret | **High** | wrong ABI on port |
| vtbl + CVOGSectorMap identity | **High** | wrong type ownership |
| Major callee groups / phases | **High** | miss subsystem bring-up |
| Every dword store English | **Low–Partial** | wrong server field map |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  *this = PTR_FUN_009cc770
  many zeros / flags (+0x7e=1)
  FUN_004e7450 ×4; FUN_004e7420 ×2
  InitCriticalSection pairs; operator_new sites
  _DAT_00b03600 = this; _DAT_00b037e4++
  return this

bytes:
  0F 57 C0 83 EC 08 53 55 56 8B F1 …
  C7 06 70 C7 9C 00
  … 8B C6 5E 5D 5B 83 C4 08 C3
```

**No conflict** on owned ABI/CF. Full field map remains open by scale, not by contradiction.

---

## 4. Surviving contract for AutoCore

```csharp
// CVOGSectorMap_Constructor @ 0x004d8a10
// retail: ECX=this (pre-allocated 0xE920), bare ret, EAX=this

CVOGSectorMap* Ctor(CVOGSectorMap* self)
{
  // Install vtbl 0x009cc770; init embedded trees/locks;
  // allocate subsystems; g_pSectorMap = self; return self.
}
```

Port rules:

- Allocate **0xE920** before call (as InitInstance does); ctor does not `new` itself.
- Do not invent SEH / HRESULT failure for this body (null child allocs store 0).
- Preserve **global publish** `_DAT_00b03600` if client code assumes singleton.
- Prefer raw store order over simplified helpers when differential-testing.

---

## 5. Open questions

1. Complete OBJECT_LAYOUTS entry for CVOGSectorMap.
2. Names of all 0x34 / 0x44 factories.
3. Whether server has a counterpart type / size.
4. Live ctor under Client_InitInstance.

**Verdict:** **accept-with-gaps**
