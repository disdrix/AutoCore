# Review A (reconstruction fidelity): `aa_00972140` AssPreloader_PreloadWorkerLoop_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972140` |
| **VA** | `0x00972140`–`0x00972421` (**738 B**) |
| **Canonical name** | `AssPreloader_PreloadWorkerLoop_Inferred` |
| **Ghidra name** | `FUN_00972140` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-K) |
| **Counterpart** | `reviews/B_aa_00972140_AssPreloader_PreloadWorkerLoop_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 738 B) + `analyze_function_complete` + caller `FUN_00972460` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

AssPreloader worker-thread body: while pending (`host+0x1c`) non-empty, drain, ticket-gate, snapshot cache factory list, load first matching geo/xml asset, record success under CS or log PRELOAD failure, yield.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00972140_FUN_00972140.md` (+ W32-K append) |
| Annotated | `docs/reconstruction/raw/aa_00972140_FUN_00972140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_PreloadWorkerLoop_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00972140.cpp` |
| Function record | `docs/reconstruction/functions/aa_00972140_FUN_00972140.md` |
| Named record | `docs/reconstruction/functions/aa_00972140_AssPreloader_PreloadWorkerLoop_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; stack host; `RET 4`; product strings |

---

## 3. Signature (sealed)

```c
// stack host; RET 4; void
void AssPreloader_PreloadWorkerLoop_Inferred(void* host /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | Stack (`MOV EBP,[ESP+0x68]`) | **High** |
| pending check | **ESI = host+0x1c** into `FUN_0043e510` | **High** |
| cleanup | **`RET 4`** | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
while FUN_0043e510(pending@+0x1c):
  FUN_00970fc0()
  if *(host+0xe0) != *FUN_0044a860(host+0xdc): continue-style skip body
  AssignTo(local, *(host+0x110)+0x28)
  for elem in local:
    path = vtbl[+0xc](elem)
    if path:
      ext = strrchr(path,'.')
      if ext == "geo": type=0; elif "xml": type=3; else: skip load
      if geo/xml: FUN_00971b80 + FUN_00971280
      CS(+0x60/gate+0x78): PushBack_Stride2(host+0x4c, {path,obj}); flag=1; break
  if none handled:
    log PRELOAD @ assPreloader.cpp:0x212
    CS(+0x90/gate+0xa8): PushBack(host+0x7c, path_slot)
  Sleep(0); FUN_0040d9c0(local)
```

| Stage | Match | Conf |
|---|---|---|
| Pending while + drain | **Yes** | **High** |
| Ticket gate +0xe0/+0xdc | **Yes** | **High** |
| geo→0 / xml→3 | **Yes** | **High** |
| Success CS + stride-2 push | **Yes** | **High** |
| Fail log + tracked push | **Yes** | **High** |
| Sleep(0) + clear local | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry / host / pending:

```
6A FF 68 4E 26 9B 00   ; SEH LAB_009b264e
...
8B 6C 24 68            ; mov ebp, [esp+0x68]  ; host
8D 75 1C               ; lea esi, [ebp+0x1c]  ; pending
E8 …                   ; call FUN_0043e510
```

Epilogue:

```
83 C4 60 C2 04 00      ; add esp,0x60; ret 4
```

Strings: `"geo"`, `"xml"`, `"PRELOAD: unable to preload asset %s"`,
`C:\vog\1_code\palantir\palantir\assets\assPreloader.cpp` line `0x212`.

Body length **738 B**. Full hex in raw W32-K append.

---

## 6. Gaps

- Product/PDB method English (file sealed; method `_Inferred`).
- Nested `FUN_00971280` / `FUN_00971b80` / `FUN_00970fc0` product plates (W32-J / residual).
- Exact fail-path semantic of push to `+0x7c` (tracked) beyond bytes.
- Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals ABI, worker loop CF, ext filter, CS offsets, product log path. Nested submit helpers open → **accept-with-gaps**.
