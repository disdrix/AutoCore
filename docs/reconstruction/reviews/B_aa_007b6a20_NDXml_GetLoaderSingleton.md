# Review B (skeptical / adversarial): `aa_007b6a20` NDXml_GetLoaderSingleton

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6a20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | "Callee of LoadVogIniConfig only" scaffold name | 50+ callers: terrain, UI, FX, creature, NDXml open | **Falsified as exclusive role** |
| 2 | General-purpose `operator new` factory | No allocation; returns fixed BSS address | **Falsified** |
| 3 | Thread-safe C++11 magic static | Guard is plain BSS bit + no lock | **Not modern static** — classic Meyers without mutex |
| 4 | Object size ≥ 0x14 including once-flag | Once-flag at `DAT_00d20c48` is separate; return is `&DAT_00d20c38` | **Do not include guard in object size without proof** |
| 5 | Name must be `NDResource_*` | Consumers are `NDXml_LoadDocumentFromPath` / OpenTagged; resource load is **inside** load path | **NDXml loader preferred**; resource is callee of load, not this |
| 6 | Init always needed before any use | All known sites call this getter first | **Stand** |
| 7 | `_atexit` registration is optional noise | First-call only; dtor path exists at `LAB_009c3040` | **Real** process-exit cleanup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / once / return pointer | **High** | Broken global load |
| flags(+4)=1 enables search path | **High** (consumer dual) | Path resolve wrong on port |
| NDXml-centric name | **High** / residual rename risk | Doc mismatch only |
| +0x08/+0x0c semantics | **Tentative** | Wrong layout docs |
| Full class identity | **Probable** | Over-narrow naming |

---

## 3. Cross-check against raw / bytes

```
raw decompile ≡ live decompile ≡ clean CF
entry: FS:[0] SEH
once: TEST/OR DAT_00d20c48 bit0
stores: vtbl, flags=1, +8=0, +c=0
call: _atexit(LAB_009c3040)
exit: MOV EAX, &DAT_00d20c38; ADD ESP,0xC; RET
```

Clean does **not** invent file I/O or COM load — those belong to `NDXml_LoadDocumentFromPath`.

---

## 4. Surviving contract for AutoCore

```
// Process-static NDXml path-loader singleton
void *NDXml_GetLoaderSingleton(void):
  static once:
    obj.vtbl  = PTR_FUN_00a95b88
    obj.flags = 1          // search-path bit for LoadDocumentFromPath
    obj+8 = 0; obj+c = 0
    atexit(dtor)
  return &obj   // DAT_00d20c38
```

Port as a process-wide singleton; do **not** allocate per call. Pass return value as `this` into `NDXml_LoadDocumentFromPath`.

---

## 5. Open questions

1. Whether any non-XML caller uses a different interpretation of the same object.
2. Complete vtable / `FUN_007b65d0` field teardown map.
3. Multi-thread first-call race (classic unprotected Meyers) — retail behavior only.

**Verdict:** **accept-with-gaps** — adversarial rejects over-narrow VOG-ini naming; singleton CF stands.
