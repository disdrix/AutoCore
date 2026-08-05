# Review A (reconstruction fidelity): `aa_00829ec0` UI_MissionJournal_MSelectEntry_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ec0` |
| **VA** | `0x00829ec0` |
| **Canonical name** | `UI_MissionJournal_MSelectEntry_Ctor_Inferred` |
| **Ghidra name** | `FUN_00829ec0` |
| **Prior scaffold** | `Mission_i_d_npc_2d_btn_mselect_xml_00829ec0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` |
| **System** | client UI / mission journal |
| **Wave** | WQ7R-E OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Ctor** for mission-journal multi-select **entry** widgets allocated as **`0x510`** bytes by `Client_UpdateMissionJournal`.

1. SEH frame + `FUN_00792d20` (`NDUIContainerPanel_Ctor_Inferred`).
2. Install subclass vtbl `PTR_FUN_00a74484`.
3. Zero/clear mselect tail: `+0x4FC`, `+0x4FD`, `+0x504`, `+0x508`, `+0x50C`; set `+0x500 = -1`.
4. `NDUIWindow_ReloadInterface("i_d_npc_2d_btn_mselect.xml")`.
5. Return `this` (`ret 4`).

**Not** mission grant/complete/fail/network. UI construction only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00829ec0_FUN_00829ec0.md` (+ WQ7R-E append) |
| Annotated | `docs/reconstruction/raw/aa_00829ec0_FUN_00829ec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionJournal_MSelectEntry_Ctor_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00829ec0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00829ec0` ≡ raw |
| Body image | `read_memory` 96+ B — vtbl, field stores, `ret 4`, string push |
| String | `read_memory` @ `0x00a74978` → `i_d_npc_2d_btn_mselect.xml` |
| Callers | xrefs + `get_assembly_context` @ `008ae38f` / `47d` / `557` / `666` |
| Peer | dual `UI_MissionJournal_BuildMSelectChrome_Inferred` (`0x00829ce0`) |
| Parent dual | `Client_UpdateMissionJournal` (`0x008ae130`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Body ~123 B; **ret 4** | `get_function_by_address`; epilogue `C2 04 00` | **High** |
| Stack `this`; return `this` | `mov esi,[esp+0x14]`; `mov eax,esi` | **High** |
| Base container ctor | `call FUN_00792d20` | **High** |
| Vtbl `00a74484` | `C7 06 84 44 A7 00` | **High** |
| Tail fields + XML | bytes + peer chrome dual offsets | **High** |
| Alloc `0x510` | call-site `push 0x510; operator_new` | **High** |
| Sole caller journal | xrefs → `Client_UpdateMissionJournal` only | **High** |
| Control ids `0x9c4f` family | parent dual + post-ctor `vtbl+0x74` | **High** (parent) |
| Product C++ name | XML + path inference | **Inferred** |
| `+0x500` exact product field | sentinel −1 only sealed | **Probable** |
| Runtime / bit-exact | not run | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| SEH + base ctor | **Yes** |
| Vtbl install | **Yes** |
| Field zero / −1 sentinel | **Yes** (bytes order: `+0x4FD` then `+0x4FC`) |
| ReloadInterface XML | **Yes** |
| Return this; ret 4 | **Yes** |
| Invented branches | **None** |

---

## 5. Residual gaps

1. Product demangled class name.
2. Full vtbl map for `PTR_FUN_00a74484`.
3. Writer(s) that fill `+0x500` after construct (probable journal bind path).
4. Runtime / differential / bit-exact image.

---

## 6. Verdict

**accept-with-gaps** — entry ctor ABI, size, skin string, tail layout, and journal call sites sealed. Gaps are product name, vtbl catalog, and runtime.
