# Review A (reconstruction fidelity): `aa_00745ee0` NDResource_AcquireInnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745ee0` |
| **VA** | `0x00745ee0` |
| **Canonical name** | `NDResource_AcquireInnerObject` |
| **Prior names** | `FUN_00745ee0` (pre-name) |
| **Review date** | `2026-07-29` (dual A/B — three-rep decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00745ee0_NDResource_AcquireInnerObject.md` |
| **System** | client resource / NDResource shell (UI XML, effects, gfx, anim) |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold dual-gap) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Acquire / pin the loaded inner payload of an `NDResource` shell:**

1. Optionally take the resource critical section (`this+0x20`) when lock flag `this+0x38 != 0`.
2. Bump refcount `*(int*)(this+0x10) += 1`.
3. Stamp last-touch time: `*(float*)(this+0x1c) = FUN_0076c330()` (rdtsc-scaled float timer).
4. Nested re-enter of the same CS (when flag set), sample `inner = *(this+0x8)`.
5. Leave once; if `inner == NULL`, call `vtbl[+0x8](this)` (shell Release).
6. Re-sample `inner = *(this+0x8)`; leave again if locked; return `inner` in `EAX`.

Callers (e.g. `NDXml_LoadDocumentFromPath`) then typically take `*(inner+4)` as a COM/`IUnknown*`-style interface and often `Release` that iface separately while later decrefing the shell via sibling `FUN_00745ea0` / inlined decref.

**Calling convention:** MSVC `__thiscall` — resource shell in `ECX`; **no stack args**; plain `ret` (not `ret N`). Ghidra may label `__fastcall` with one ECX param — equivalent for this ABI.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | `NDResource*` shell | all call sites; `mov esi,ecx` body |
| EAX | `void*` / inner object at `this+0x8` (nullable) | `mov eax,esi` after `mov esi,[esi+8]` |
| stack | none | plain `ret` @ body end |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00745ee0_NDResource_AcquireInnerObject.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00745ee0_NDResource_AcquireInnerObject.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResource_AcquireInnerObject.cpp` |
| Function record | `docs/reconstruction/functions/aa_00745ee0_NDResource_AcquireInnerObject.md` |
| Live decompile | Ghidra `decompile_function` `0x00745ee0` **×3** (2026-07-29) — identical body |
| Live bytes | `read_memory` `0x00745ee0` length 160; body `0x00745ee0`–`0x00745f70` then `int3` pad |
| Signature meta | `get_function_signature`: 52 insns, 11 BB, callees Enter/Leave/FUN_0076c330 |
| Callers | `get_function_callers` + `get_xrefs_to` — **18** `UNCONDITIONAL_CALL` sites |
| Callees | `get_function_callees` + body: EnterCS, LeaveCS, `FUN_0076c330`, virtual `vtbl+8` |
| Timer leaf | `decompile_function` `0x0076c330` (rdtsc / scale globals) |
| Sibling decref | `FUN_00745ea0` @ `0x00745ea0` — same `+0x10` / `+0x20` / `+0x38` layout |
| Consumer | `NDXml_LoadDocumentFromPath` @ `0x007b6c70` (+ call-site bytes @ `0x007b6d90`) |

**Not performed:** `disassemble_bytes`, Launcher, live process memory, bit-exact image diff, PDB symbol string hunt.

---

## 3. Control flow: clean ≡ raw ≡ live bytes

| Stage | Match |
|---|---|
| SEH prologue (`push -1`, handler `LAB_009ac157`, FS:[0]) | **Yes** |
| `this` → ESI; CS base `EDI = this+0x20` | **Yes** — `mov esi,ecx` / `lea edi,[esi+0x20]` |
| Gate lock: `cmp byte [this+0x38],0` | **Yes** — first check on ESI; later checks on `[edi+0x18]` ≡ `this+0x38` |
| If locked: `EnterCriticalSection(this+0x20)` | **Yes** — `call [IAT Enter]` via EBX |
| `*(this+0x10) += 1` | **Yes** — `add dword [esi+0x10],1` |
| `FUN_0076c330()` → `fstp dword [this+0x1c]` | **Yes** — decompiler `(int)(float)` is **FPU float store**, not int |
| If locked: **second** `EnterCriticalSection` | **Yes** — nested Enter (recursive CS) |
| Sample `inner = *(this+0x8)`; `setne bl` | **Yes** |
| If locked: `LeaveCriticalSection` | **Yes** — via EBP = Leave IAT |
| If `bl==0` (was null): `this->vtbl[+0x8]()` with ECX=this | **Yes** — `call [eax+8]` |
| Re-load `ESI = *(this+0x8)` | **Yes** — after optional Release |
| If locked: second Leave | **Yes** |
| Return EAX = ESI (inner); SEH teardown; plain `ret` | **Yes** |
| No stack args | **Yes** |

### 3.1 Nested CS Enter×2 / Leave×2 — **SEALED as product**

When `this+0x38 != 0`, bytes perform **Enter → (mutate) → Enter → Leave → (maybe Release) → Leave**. Requires **recursive** `CRITICAL_SECTION`. Not a decompiler Leave/Enter swap: first pair uses EBX (Enter IAT @ `0x009c61bc`); leave pair uses EBP (Leave IAT @ `0x009c61b8`).

When flag is 0: **no** CS calls; still bumps refcount + stamps time + null-inner Release.

### 3.2 Decompiler noise — **SEALED as artifact**

| Noise | Reality |
|---|---|
| `__fastcall` label | **thiscall** ECX; no stack params |
| `param_1[N]` int indexing | byte offsets `N*4` (`[4]→+0x10`, `[2]→+0x8`, `[7]→+0x1c`, `[0xe]→+0x38`) |
| `float10` / `(int)(float)` on timer | **`fstp dword [this+0x1c]`** — store **float32** |
| `LPCRITICAL_SECTION (param_1+8)` | address of field at **byte +0x20** |

Three independent `decompile_function` pulls (2026-07-29) returned **identical** pseudocode (stable vs 2026-07-23 raw body).

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| `this+0x00` | ptr | vtbl | `mov eax,[esi]` before virtual call |
| `this+0x08` | ptr | **inner object** (return value) | `cmp [esi+8]` / `mov esi,[esi+8]` |
| `this+0x10` | i32 | **refcount** (incremented) | `add dword [esi+0x10],1` |
| `this+0x1c` | f32 | **last-acquire time** (rdtsc scale) | `fstp dword [esi+0x1c]` |
| `this+0x20` | `CRITICAL_SECTION` | optional lock object | `lea edi,[esi+0x20]` |
| `this+0x38` | u8 | **use-CS flag** (nonzero → lock) | `cmp byte [esi+0x38]` / `[edi+0x18]` |
| vtbl `+0x08` | method | shell **Release** when inner null | `call [eax+8]` |
| inner `+0x04` | ptr | COM/iface (caller-side; not body) | `NDXml` `mov ebx,[eax+4]` |

Sibling `FUN_00745ea0` (decref): same `+0x10` / `+0x20` / `+0x38` — High layout corroboration.

---

## 5. Callees

| Target | Role |
|--------|------|
| `EnterCriticalSection` | optional nested lock |
| `LeaveCriticalSection` | matching unlocks |
| `FUN_0076c330` @ `0x0076c330` | rdtsc-based float time (lazy-init `DAT_00d1a530` scale) |
| `(*this->vtbl)[+0x08]` | shell Release on null-inner path |

---

## 6. Callers (18 UNCONDITIONAL_CALL)

| Site | Function (Ghidra) | Consumer pattern (summary) |
|------|-------------------|----------------------------|
| `0x007b6d9c` | `NDXml_LoadDocumentFromPath` | inner → `*(inner+4)` COM Release / VARIANT load |
| `0x007b7170` | `FUN_007b70e0` | resource cache → acquire |
| `0x007b7340` | `FUN_007b72b0` | same family |
| `0x007b728f` | `FUN_007b7250` | terrain / tint map path family |
| `0x007b74c9` | `FUN_007b7420` | sky/particles family |
| `0x0075347d` | `FUN_007533e0` | gfx sub-phase map |
| `0x0074fd93` | `FUN_0074fd90` | effect device / texture family |
| `0x0074fe79` | `FUN_0074fe70` | effect sibling |
| `0x0074ee7d` | `FUN_0074ee40` | cache lookup path |
| `0x00764911` | `FUN_00764830` | gfx body |
| `0x0076421b` | `FUN_007641c0` | gfx body helper |
| `0x0096a500` | `FUN_0096a440` | effect pool / Palantir family |
| `0x0096bcf7` | `FUN_0096bcf0` | effect texture impl |
| `0x0096c2cd` | `FUN_0096c2c0` | effect sibling |
| `0x0096ecd2` | `FUN_0096ea60` | texture factory family |
| `0x00981f8d` | `FUN_00981f50` | anim master family |
| `0x00448f92` | `FUN_00448f50` | anim master family |
| `0x004453de` | (unnamed site) | direct call xref |

Pattern sealed: **resource shell is `this`**; return is **inner payload pointer** (may be null after Release path).

---

## 7. Naming

| Claim | Confidence |
|---|---|
| Role = acquire/pin inner object + bump ref + touch time | **High / Sealed** |
| Canonical `NDResource_AcquireInnerObject` | **High** (Ghidra plate + widespread named callers) |
| Sibling `FUN_00745ea0` = shell decref (not this unit) | **High** |
| `FUN_0076c330` product English timer name | **Open** (role sealed: float time) |
| vtbl+8 product name (`Release` / `NDResource::Release`) | **Probable** (IUnknown-shaped; not PDB-proven) |

---

## 8. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** (`0x00745ee0`–`0x00745f70`, ~0x90 B) |
| Signature (`__thiscall`, 0 stack args, EAX return) | **High** |
| Control flow (3-rep decompile ≡ raw ≡ bytes) | **High** |
| Offsets `+8/+10/+1c/+20/+38` | **High / Sealed** |
| Nested CS Enter×2 when locked | **High / Sealed** |
| Null-inner → vtbl+8 | **High** |
| Timer = float via `FUN_0076c330` | **High** (bytes `fstp`) |
| Product timer / Release English names | **Open** |
| Runtime / bit-exact | **Open** |
| Overall | **accept-with-gaps** |
