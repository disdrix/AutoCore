# Review A (reconstruction fidelity): `aa_004642d0` HeadBag_Ctor_Sentinel0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004642d0` |
| **VA** | `0x004642d0`–`0x00464332` exclusive (**98 B** / `0x62`) |
| **Canonical name** | `HeadBag_Ctor_Sentinel0x14_Inferred` |
| **Ghidra name** | `FUN_004642d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-H) |
| **Counterpart** | `reviews/B_aa_004642d0_HeadBag_Ctor_Sentinel0x14_Inferred.md` |
| **System** | list-head + pointer-vector bag (0x14 circular sentinel) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 98 B) + xrefs/bulk + nested `FUN_0043c460` decompile/bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Placement constructor for a list-head + 9-bucket pointer-vector bag using a **0x14** circular sentinel (not the AssResolver 0x28 twin).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-H append) | `docs/reconstruction/raw/aa_004642d0_FUN_004642d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004642d0_FUN_004642d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/HeadBag_Ctor_Sentinel0x14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004642d0.cpp` |
| Function records | `functions/aa_004642d0_FUN_004642d0.md`, named twin |
| Nested | `FUN_0043c460` decompile + 26 B (`new(0x14)` circular); `FUN_004646e0` W33-B |
| Twin CF | `FUN_00423cf0` / `FUN_00469db0` (0x28 sentinel bags) |
| Live | decompile ≡ bytes for CF; `C2 04 00`; 0 static xrefs |

---

## 3. Signature (sealed — bytes win)

```c
// stack(self*); RET 4; return self; SEH LAB_009bdd3b
HeadBag_Sentinel0x14* __stdcall HeadBag_Ctor_Sentinel0x14_Inferred(
    HeadBag_Sentinel0x14* self);
```

| Formal | Source | Conf |
|---|---|---|
| self* | stack @ entry (`[esp+0x18]` after prolog → ESI) | **High** |
| RET 4 | `C2 04 00` | **High** |
| return self | `mov eax,esi` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH prolog LAB_009bdd3b
head = FUN_0043c460()          // new(0x14) circular next/prev
self[+0x08] = head
self[+0x0c] = 0
local_fill = head
FUN_004646e0(self+0x10, 9, &local_fill)   // 9 ptr slots = head
self[+0x20] = 1
self[+0x24] = 1
SEH epilog
mov eax, self; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Sentinel via 0043c460 (0x14) | **Yes** | **High** |
| Layout +08/+0c/+10/+20/+24 | **Yes** | **High** |
| count 9 fill | **Yes** (`6A 09`) | **High** |
| Twin of 00423cf0/00469db0 CF | **Yes** (diff sentinel only) | **High** |
| Static callers | **None** | **High** (xrefs + byte search) |

---

## 5. Gaps

- Product English / owning type (not AssResolver — different sentinel size).
- Meaning of flags +0x20/+0x24 and unwritten +0x00/+0x04.
- Why zero static callers (dead vs dynamic vs missed data ref).
- Nested `FUN_0043c460` product plate (not owned).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals placement ABI, layout, 0x14 sentinel, 9-slot fill, and twin CF distinction. Residual product owner + 0 xrefs → **accept-with-gaps**.
