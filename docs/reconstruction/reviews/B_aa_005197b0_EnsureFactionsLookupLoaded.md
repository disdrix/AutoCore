# Review B (skeptical / adversarial): `aa_005197b0` EnsureFactionsLookupLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_005197b0` |
| **VA** | `0x005197b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9R-F) |
| **Counterpart** | `reviews/A_aa_005197b0_EnsureFactionsLookupLoaded.md` |
| **Tools** | decompile + read_memory + xrefs + loader callee (no Launcher, no disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is skill-bank residual logic | WQ-009 wave label | **Falsified as domain** — loads **factions** table; skill-bank cast not present |
| 2 | Body early-outs if already loaded | “Ensure” naming | **Falsified for this body** — always Recreate+Load; **caller** `FUN_0051a120` gates on `DAT_00b04320==0` |
| 3 | `//tFactions/row` string is in this function | name claim | **Indirect** — string is in **callee** `FUN_007ce550`; still seals table identity |
| 4 | `operator_delete` never returns (end loop) | Ghidra warning | **Falsified** — free of temp vector then SEH restore / return |
| 5 | `lpString == (LPCWSTR)0x40` is real null-object sentinel | decompiler literal | **Hazard** — arithmetic artifact; intent is null check on first wide field pointer |
| 6 | Inserts own hash without this | decompile `FUN_0051e5d0(id,rec,0)` | **Incomplete ABI** — ECX forced to `0x00b04314` |
| 7 | Fail always terminates process | VOG_DEBUG_STOP / HRESULT throws | **Partial** — load fail logs and continues empty walk; WCMAP fail calls `FUN_004048c0` (throw path) |

---

## 2. Surviving contract

```
void EnsureFactionsLookupLoaded(void):
  CNDHash_Recreate(&g_FactionHash@0x00b04314, power=4)
  DbEnter(*g_pDbReaderCtx@0x00b0469c)
  status = LoadTFactionsRows(... → vector stride 0xc4)  // FUN_007ce550, xpath //tFactions/row
  DbLeave(*g_pDbReaderCtx)
  if status < 0: log VOG_DEBUG_STOP
  for each row:
    rec = new 0x64 { id, mbcsA@+4, mbcsB@+0x24 }
    CNDHash_Insert(hash, id, rec, allowDup=0)
  free temp vector
```

Lookup consumer (not owned): `FUN_0051a120(id)` → payload at node+8 after ensure.

---

## 3. Open questions

1. Column semantics of the two strings (name vs description?).
2. Who writes non-zero `DAT_00b04320` (insert count field?).
3. Idempotence if Ensure called while hash already populated (Recreate should wipe).
