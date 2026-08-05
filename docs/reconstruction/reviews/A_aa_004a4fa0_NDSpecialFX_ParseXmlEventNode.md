# Review A (reconstruction fidelity): `aa_004a4fa0` NDSpecialFX_ParseXmlEventNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a4fa0` |
| **VA** | `0x004a4fa0` |
| **Body span** | `004a4fa0` – `004a617f` |
| **Canonical name** | `NDSpecialFX_ParseXmlEventNode` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004a4fa0_NDSpecialFX_ParseXmlEventNode.md` |
| **System** | `client-fx` / NDSpecialFX |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Parse a single **special-FX event XML node** into a heap FX object:

1. Read type-name attribute → integer event id (fixed table or custom ≥ 100).
2. `operator_new(0x240)` + `FUN_004ba310` ctor; store id at **`fx+0x28`**.
3. Optional float into **`fx+0x58`**.
4. Enumerate children; dispatch by element name to Group / Particle / Geometry / Trail / Lightning / Sound / MusicEvent / Force / Include / Parameter / Fluid loaders.
5. Fail paths: `FUN_004b99c0` + `operator_delete` (often noreturn); soft fail return **NULL**.

Primary callers: script load (`NDSpecialFX_LoadFromScriptName`), master XML (`FUN_004a6390`), `FUN_004a6670`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a4fa0_FUN_004a4fa0.md` (+ live append) |
| Annotated | `docs/reconstruction/raw/aa_004a4fa0_FUN_004a4fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004a4fa0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_ParseXmlEventNode.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a4fa0_FUN_004a4fa0.md` |

**This pass (live, OWN VA only):**

- Ghidra MCP `decompile_function` @ `0x004a4fa0` — full body (~750 lines); matches prior raw CF + string tables.
- Ghidra MCP `read_memory` @ entry / epilogue / `DAT_009c9ef0` / `DAT_009c7c28`.
- `get_function_by_address` — `004a4fa0`–`004a617f`.
- `get_function_xrefs` — 3 callers (all FX load paths).
- **Not performed:** Launcher, runtime golden; **no ownership** of child loader / ctor / teardown VAs.

---

## 3. Calling convention (assembly-sealed on OWN body)

| Slot | Role | Evidence |
|---|---|---|
| **[ebp+8]** | XML node iface* | `mov eax,[ebp+8]; mov ecx,[eax]; call [ecx+0x44]` |
| **[ebp+0xC]** | `int *outEventType` | writes `*param_2 = …` throughout type map |
| **[ebp+0x10]** | `uint8_t *customCounter` | `*param_3 + 100` / `++` on unknown type |
| **Return** | `void *fx` or `NULL` | success `return pvVar5`; fail `xor eax,eax; ret` |
| **Cleanup** | `__cdecl` | epilogue `leave; ret` (no `ret N`) |

**Correction:** Ghidra type `BSTR param_1` is **wrong** — prologue proves COM/XML vtable object.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + cdecl | **High** | bounds + epilogue |
| Arg0 XML node, not BSTR | **High** | vtbl call |
| Full event-type wcsicmp table (24 fixed + custom) | **High** | live decompile strings |
| Group owner attach-id table | **High** | incl. `DAT_009c9ef0` = `L"top"` |
| `fx+0x28 = eventType` | **High** | direct store |
| Sound block `0x138`, radius 10 / max 80 | **High** | `read_memory` floats |
| Sound category defaults by event | **High** | switch on `*param_2` |
| Child name dispatch set | **High** | string compares |
| MusicEvent only when eventType==Create (0) | **High** | `*param_2 == 0` guard |
| Fluid gated by `DAT_00af06e8` | **High** | decompile |
| Force at `fx+0x60`, backlink `+0x2c` | **High** | stores |
| Child-count / unaff_* recovery | **Medium–Low** | decomp noise; loop still present |
| Callee product names (Particle loader etc.) | **Tentative** | call shape only |
| Clean ≡ raw string/dispatch CF | **High** | tables extracted faithfully |
| Full line-by-line stack frame identity in clean | **Partial** | clean is CF map, not 0x958-frame mirror |
| Runtime / bit-exact | **Open** | deferred |

---

## 5. Control flow checklist (clean ≡ raw ≡ live)

| Stage | Match |
|---|---|
| vtbl+0x44 gate + null primary → fail NULL | **Yes** |
| Type attr via `FUN_00798bb0` | **Yes** |
| Type name → id table / custom+100 | **Yes** |
| new 0x240 + ctor; `+0x28` store | **Yes** |
| Optional `+0x58` float | **Yes** |
| Children enum; null → teardown+delete | **Yes** |
| Per-child name dispatch | **Yes** |
| Group owner map + `FUN_004a7f80` | **Yes** |
| Particle/Include fail → teardown | **Yes** |
| Trail/Lightning null → teardown | **Yes** |
| Sound / MusicEvent attr blocks | **Yes** (attr list High; packing residual) |
| Force / Parameter / Fluid | **Yes** |
| Success return fx; fail NULL | **Yes** |

---

## 6. Gaps

1. **IXml vtbl** slot product names (`+0x44/+0x30/+0x20/+0x1c/+8`) not sealed.
2. **Child loaders / ctor / teardown** bodies out of OWN scope.
3. **Decompiler local recovery** (`unaff_ESI/EDI`, reused `pvStack_958`) — do not treat as typed fields.
4. **4th caller arg** (`pszName` in sibling `LoadFromScriptName` plate) unused in this body — ignore on this VA.
5. Clean is a **structural CF map** with helper extractors for sealed tables, not a byte-identical stack frame transcription.
6. Runtime / differential **Open**.
7. Ghidra “unreachable block `0x004a5789`” not re-lifted.

**Verdict:** **accept-with-gaps** — event-type and group-owner tables, dispatch set, object offsets `+0x28/+0x58/+0x60`, sound defaults, and success/fail ownership CF are **High** for AutoCore FX ports; leave child loader semantics and XML iface names residual.
