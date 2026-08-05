# Review A (reconstruction fidelity): `aa_0044af00` Phy_CPConnection_AssertConnectionPoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044af00` |
| **VA** | `0x0044af00` |
| **Canonical name** | `Phy_CPConnection_AssertConnectionPoint` |
| **Review date** | `2026-07-29` (machine seal; prior string scaffold 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0044af00_Phy_CPConnection_AssertConnectionPoint.md` |
| **System** | `physics` / phyCPConnection |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + caller `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** (CF/ABI/refcount High; owner+0x64 list type + vtable slot names Probable) |

---

## 1. Purpose

**Assert / bind a connection-point smart pointer** for a physics owner object:

1. If **connection id == −1**: treat as explicit “no point” — write owner through `*pOutOwner`, **Release** any prior smart-ptr slot, clear slot, return **0**.
2. Else **lookup** id on **`owner+0x64`** via callee `FUN_0040d4b0` / `Named_CalleeOf_Named_phyCPConnection_0040d4b0`.
3. On hit: write owner, **AddRef** the connection-point object (and call **vtable+4** on 0→1), Release prior slot, store new object*, return **0**.
4. On miss: `vog_LogMessage` from `phyCPConnection.h` line **0x8F (143)** level **3** — `"Connection point not found!"` — clear owner out + smart slot (Release), return **−1**.

Callers (special events / attach helpers) allocate a **0x10** pair-block and invoke this **twice** (two connection ids → slots `{owner0,sp0,owner1,sp1}`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044af00_FUN_0044af00.md` |
| Annotated | `docs/reconstruction/raw/aa_0044af00_FUN_0044af00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_CPConnection_AssertConnectionPoint.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044af00_Phy_CPConnection_AssertConnectionPoint.md` |
| Callee (context, not owned) | `0x0040d4b0` list find-by-id at `this` registry |
| Callers (context) | `FUN_0096dc80`, `FUN_00855ff0`, `ClientSpecialEvent_TeleportIn_ctor`, `ClientSpecialEvent_Respawn_Update`, `FUN_009784f0` |

---

## 3. Seal: body (`read_memory` @ `0x0044af00`)

Body range **`0x0044af00`–`0x0044af97`** (`ret`; **152** bytes), padding `CC` after. Hex:

```
83 f8 ff 56 8b f1 75 18 89 37 8b 0b 85 c9 74 0a
01 41 04 75 05 8b 01 ff 50 08 33 c0 89 03 5e c3
50 8d 4e 64 e8 87 25 fc ff 85 c0 74 30 89 37 8b 30
85 f6 74 11 83 46 04 01 83 7e 04 01 75 07 8b 16 8b ce
ff 52 04 8b 0b 85 c9 74 0b 83 41 04 ff 75 05 8b 01
ff 50 08 89 33 33 c0 5e c3 68 a8 08 aa 00 6a 03 68
8f 00 00 00 68 80 08 aa 00 e8 4d be 54 00 c7 07 00 00
00 00 8b 0b 83 c4 10 85 c9 74 0b 83 41 04 ff 75 05
8b 11 ff 52 08 83 c8 ff c7 03 00 00 00 00 5e c3
```

### Control flow (machine)

```
; inputs: EAX=connId, ECX=owner, EBX=pSmartPtrSlot (obj**), EDI=pOutOwner (void**)
cmp  eax, -1
push esi
mov  esi, ecx                 ; esi = owner
jnz  lookup

; --- connId == -1 (explicit none) ---
*pOutOwner = owner
old = *pSmartPtrSlot
if old:
  old.refCount += eax        ; eax still -1 → decrement
  if refCount == 0: call [vtbl+8]
*pSmartPtrSlot = null
return 0

lookup:
push eax                     ; stack formal = connId
lea  ecx, [owner+0x64]       ; thiscall registry
call FUN_0040d4b0            ; → 0x0040d4b0
if result == null → not_found

*pOutOwner = owner
obj = *result                ; list node payload at node+2
if obj:
  obj.refCount++
  if refCount == 1:
    thiscall obj; call [vtbl+4]   ; first-acquire hook
old = *pSmartPtrSlot
if old: Release (ref-- ; vtbl+8 if 0)
*pSmartPtrSlot = obj
return 0

not_found:
vog_LogMessage("..\\palantir/physics/phyCPConnection.h", 0x8f, 3,
               "Connection point not found!")
*pOutOwner = null
Release *pSmartPtrSlot if any
*pSmartPtrSlot = null
return 0xffffffff
```

### ABI (multi-register — decompiler residual)

| Item | Machine | Conf |
|---|---|---|
| **EAX** | `int connectionPointId` (`-1` = none) | **High** |
| **ECX** | `owner*` (written to `*EDI` on success / none) | **High** |
| **EBX** | `RefCountedObject**` smart-pointer slot out | **High** |
| **EDI** | `void**` owner-out slot | **High** |
| Stack formals | none; **`ret`** (not `ret N`) | **High** |
| Return | **0** ok / **−1** not found | **High** |
| Decompiler `__fastcall(param_1)` + `in_EAX` / `unaff_EBX` / `unaff_EDI` | **Residual** — real formals are EAX/ECX/EBX/EDI | **High** (artifact only) |

### Refcount object shape (this unit)

| Offset | Field | Access |
|---|---|---|
| `+0x00` | `pVTable` | load for virtuals |
| `+0x04` | `nRefCount` | ++ / −− |
| vtbl **`+0x04`** | first-acquire / OnAddRef-from-zero | only when count becomes **1** after ++ |
| vtbl **`+0x08`** | last-release / destroy | when count hits **0** after −− |

### Callee `0x0040d4b0` (used, not dual-owned)

- **thiscall** `FindConnectionPointById(registry=owner+0x64, id)`.
- Walks intrusive list at `*(*registry + 0xC)`; matches `*(node[2] + 8) == id`; returns **`node+2`** (pointer to payload object*) or null.
- Assert path: `obj = **(returned node+2)` i.e. `mov esi,[eax]`.

### Strings (`read_memory`)

| VA | Content |
|---|---|
| `0x00aa0880` | `..\\palantir/physics/phyCPConnection.h` |
| `0x00aa08a8` | `Connection point not found!` |

### Caller register setup (sample)

```
; first of two binds (e.g. 0096dd0a / 00856241)
mov  eax, <connId>           ; e.g. 0x1F / 0x23 / stack param
lea  ebx, [pairBlock + 4]    ; smart-ptr slot
mov  edi, pairBlock          ; owner-out slot
mov  ecx, owner             ; often EBP / reaction this
call 0x0044af00
; second bind: lea edi,[pair+8]; lea ebx,[pair+0xC]; eax = other id (often 0)
```

Success gate at callers: both returns **0** before continuing attach; else tear down pair + `FUN_0044adc0` / delete.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-reg ABI EAX/ECX/EBX/EDI; `ret` 0 | **High** | body + 10 call-site setups |
| `connId == -1` → clear smart slot, write owner, ret 0 (no log) | **High** | `cmp eax,-1` path; Release uses `add [ecx+4],eax` with eax still −1 |
| Lookup `thiscall(owner+0x64, id)` → `0x0040d4b0` | **High** | `push eax; lea ecx,[esi+0x64]; call` |
| Not found → log line **143** level **3** + ret **−1** | **High** | immediates + strings |
| Smart-ptr replace = AddRef new + Release old | **High** | symmetric ref protocol |
| First-acquire only when ref becomes 1 | **High** | `cmp [esi+4],1` after ++ |
| Name from `phyCPConnection.h` + assert string | **High** | NAMING + strings |
| Semantic name of vtbl+4 / +8 (AddRef vs OnLock) | **Probable** | protocol shape clear; names inferred |
| Exact C++ type of object at `owner+0x64` | **Tentative** | registry blob; list layout from callee only |
| Connection id enum (0x1F/0x23/0 …) meanings | **Open** | caller constants; not decoded here |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match after seal |
|---|---|
| −1 → write owner, Release slot, ret 0 | **Yes** |
| Lookup at owner+0x64 | **Yes** (clean plate updated) |
| Hit → AddRef / optional vtbl+4 / swap slot / ret 0 | **Yes** |
| Miss → log / clear outs / ret −1 | **Yes** |
| Prior scaffold `unaff_*` as unknown | **Resolved as real formals** |

---

## 6. Gaps / open

1. Full type of connection-point object and registry at `+0x64` (header-level names).
2. Catalog of connection-point id constants across callers.
3. Whether vtbl+4 is COM-style AddRef or a one-shot “lock/load” side effect.
4. Runtime / bit-exact harness not run.

**Verdict:** **accept-with-gaps**
