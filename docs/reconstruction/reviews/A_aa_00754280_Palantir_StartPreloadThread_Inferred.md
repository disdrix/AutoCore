# Review A (reconstruction fidelity): `aa_00754280` Palantir_StartPreloadThread_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754280` |
| **VA** | `0x00754280`–`0x007542e8` (**105 B**) |
| **Canonical name** | `Palantir_StartPreloadThread_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00754280` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-F) |
| **Counterpart** | `reviews/B_aa_00754280_Palantir_StartPreloadThread_Inferred.md` |
| **System** | Palantir / thrThread preload |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 105 B) + `analyze_function_complete`; callers/callees; string plates |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Start (once) the Palantir preload thrThread stored at host `+0xd4`. Already-running → log + AL=0; else allocate thrThread(0x10), store, CreateThread via thrThread helper with 0x40000 stack, AL=1.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00754280_FUN_00754280.md` (+ 2026-07-29 W31-F append) |
| Annotated | `docs/reconstruction/raw/aa_00754280_FUN_00754280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_StartPreloadThread_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754280.cpp` |
| Function record | `docs/reconstruction/functions/aa_00754280_FUN_00754280.md` |
| Named record | `docs/reconstruction/functions/aa_00754280_Palantir_StartPreloadThread_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; call-site `MOV EDI,[DAT_00d1f058]` |

---

## 3. Signature (sealed)

```c
// EDI=host; 0 stack formals; plain RET; AL 0/1
uint8_t Palantir_StartPreloadThread_Inferred(void* host /*EDI*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | **EDI** (`[EDI+0xD4]` loads/stores; callers load `*DAT_00d1f058` into EDI) | **High** |
| stack formals | none | **High** |
| cleanup | plain `RET` (`C3`) | **High** |
| return | **AL** 0 (already) / 1 (started path) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if host+0xd4 != 0:
  log Palantir.cpp:0x1fd "Preload thread already runnning."
  return AL=0
raw = new(0x10)
if raw:
  vftable=PTR_FUN_00a9e9bc; zero id/handle; context=*(DAT_00d1f050+0x6c)
  ESI = raw
else:
  ESI = 0
host+0xd4 = ESI
thrThread_Create(ESI, EDX=0x40000, AL=0)
return AL=1
```

| Stage | Match | Conf |
|---|---|---|
| Already-running gate + log | **Yes** | **High** |
| new 0x10 + vftable/context | **Yes** | **High** |
| Store `+0xd4` including null | **Yes** | **High** |
| Create args ESI/EDX/AL | **Yes** (bytes; decompile incomplete) | **High** |
| Return 1 after create attempt | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body (105 B):

```
56 33 F6 39 B7 D4 00 00 00 74 1D 68 D8 F7 A9 00
6A 02 68 FD 01 00 00 68 10 F9 A9 00 E8 1F 2B 24
00 83 C4 10 32 C0 5E C3 6A 10 E8 E3 55 D3 FF 83
C4 04 3B C6 74 1D 89 70 0C 89 70 04 89 70 08 C7
00 BC E9 A9 00 8B 0D 50 F0 D1 00 8B 51 6C 89 50
0C 8B F0 BA 00 00 04 00 32 C0 89 B7 D4 00 00 00
E8 0B 6C FC FF B0 01 5E C3
```

Key immediates: `+0xD4`, line `0x1FD`, size `0x10`, vftable `0x00A9E9BC`, global `0x00D1F050`, stack `0x40000`.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDI host ABI | **High** | both call sites |
| Preload thrThread once-gate | **High** | string + field |
| Create stack 0x40000 | **High** | `MOV EDX,0x40000` |
| Product method English | **Inferred** | plates only |
| Start routine body | **Open** | `LAB_0071aed0` not OWN |

---

## 7. Gaps

1. Product/PDB Palantir method name.
2. thrThread start routine / join counterparts (not OWN).
3. OOM path: retail still calls create with ESI=0 and returns 1.
4. Runtime / bit-exact under live client.

**Verdict:** CF/ABI/strings sealed; residual is callee/product/runtime → **accept-with-gaps**.
