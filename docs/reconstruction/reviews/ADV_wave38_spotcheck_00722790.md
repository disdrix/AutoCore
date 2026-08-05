# Independent adversarial spot-check — W38-AG dual `0x00722790`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** W38-AG dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | W38-AG OWN `aa_00722790` |
| **Unit** | `0x00722790` `CSoundManager_AppendOggOrLxxExt_Inferred` (mission / client audio path) |
| **Tools** | Ghidra MCP `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs`; artifact read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00722790-w38ag-report.md` |
| `docs/reconstruction/reviews/A_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |

### Artifacts

| Kind | Path |
|---|---|
| Raw (+ W38-AG append) | `docs/reconstruction/raw/aa_00722790_FUN_00722790.md` |
| Annotated | `docs/reconstruction/raw/aa_00722790_FUN_00722790.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CSoundManager_AppendOggOrLxxExt_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00722790.cpp` |
| Function record | `docs/reconstruction/functions/aa_00722790_FUN_00722790.md` |
| Named function | `docs/reconstruction/functions/aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `decompile_function(0x00722790)` | Live body ≡ raw scaffold CF (default `"_lxx.ogg"`, flag@`+0x308` zero → `".ogg"`, strlen walks, dword/byte bulk copy, void return) |
| `get_function_by_address` | Body **`00722790`–`007227de`**; stale signature `undefined FUN_00722790(void)` (noise — dual correctly privileges decompile + bytes) |
| `get_function_xrefs` | **6** UNCONDITIONAL_CALL sites (table below) — **exact match** to dual |
| `read_memory` 128 B @ entry | Full 78 B body + `CC` pad + next prologue; hex ≡ dual W38-AG append |
| `read_memory` @ `0x00A9D9A4` | `2e 6f 67 67 00` → `".ogg"` |
| `read_memory` @ `0x00AA91A0` | `5f 6c 78 78 2e 6f 67 67 00` → `"_lxx.ogg"` |
| `decompile_function(0x00724870)` | Probe: copies path → `FUN_00722790(local_208)` then `PathFileExistsA` (decompiler drops ECX; bytes seal thiscall) |
| `decompile_function(0x00723820)` | `Client_GetMissionCompleteAudioTable` → returns `&DAT_00d20210` |
| Call-site bytes @ `0x00724890` | `mov ecx,[esp+0x214]`; `lea`/`push` path; `call FUN_00722790` |
| Call-site bytes @ `0x004B8CD0` | `push` path; `call Client_GetMissionCompleteAudioTable`; `mov ecx,eax`; `call FUN_00722790` @ `0x004B8CE9` |

### Body hex seal (independent `read_memory`)

78 B (`0x00722790`–`0x007227de` exclusive), then pad `CC`, next @ `0x007227e0`:

```
80b90803000000b8a091aa007505b8a4d9a9008bd08a0883c00184c975f7
56578b7c240c2bc283c7ff8da424000000008a4f0183c70184c975f68bc8
c1e9028bf2f3a58bc883e103f3a45f5ec20400
```

| Bytes | Meaning | Dual claim |
|---|---|---|
| `80 B9 08 03 00 00 00` | `cmp byte ptr [ecx+0x308], 0` | **OK** |
| `B8 A0 91 AA 00` | `mov eax, 0x00AA91A0` (`"_lxx.ogg"` default) | **OK** |
| `75 05` | `jnz` keep `_lxx` | **OK** |
| `B8 A4 D9 A9 00` | `mov eax, 0x00A9D9A4` (`".ogg"` when flag==0) | **OK** |
| `8B 7C 24 0C` | `edi = pathBuf` after `push esi/edi` | **OK** |
| `F3 A5` / `F3 A4` | `rep movsd` + residual `rep movsb` | **OK** |
| `C2 04 00` | **`RET 4`** | **OK** |
| No `E8`/`E9`/`FF15` in body | Leaf (no callees) | **OK** |

### Xrefs (live)

| Site | Parent | Dual claim |
|---|---|---|
| `0x007248A0` | `FUN_00724870` | **OK** |
| `0x004B8CE9` | `FUN_004B88E0` | **OK** |
| `0x004B8D4B` | `FUN_004B88E0` | **OK** |
| `0x00720E6A` | `FUN_00720DA0` | **OK** |
| `0x00721C06` | `FUN_00721A80` | **OK** |
| `0x00721968` | `FUN_007217C0` | **OK** |

---

## Confirmed claims

| Claim | Verdict |
|---|---|
| Body range `00722790`–`007227de` (78 / `0x4E` B); pad `CC`; next @ `007227e0` | **Confirmed** |
| Live decompile ≡ raw CF ≡ dual sealed algorithm | **Confirmed** |
| **thiscall**: ECX = host*; stack `char* pathBuf`; **`RET 4`**; void | **Confirmed** (bytes + call sites) |
| Flag `*(char*)(host+0x308)==0` → `".ogg"` @ `0x00A9D9A4` (5 B incl NUL) | **Confirmed** |
| Flag ≠0 → `"_lxx.ogg"` @ `0x00AA91A0` (9 B incl NUL) | **Confirmed** (default load before jnz) |
| Append-not-replace (no scan for existing `.`) | **Confirmed** |
| strcat-equivalent: suffix length incl NUL; copy onto path end | **Confirmed** |
| No capacity / bounds check on `pathBuf` | **Confirmed** |
| Leaf (callees empty) | **Confirmed** |
| 6 callers as dualed; Probe uses CSoundManager this in ECX | **Confirmed** |
| 5/6 non-probe sites load ECX from `Client_GetMissionCompleteAudioTable` → `&DAT_00d20210` | **Confirmed** (sample site + getter decompile) |
| Clean named ≈ `strcat(path, suffix)` CF-faithful modernization | **Confirmed** (not bit-exact; dual defers bit-exact) |
| Clean twin mirrors decompile walks + `rep movs*` | **Confirmed** |
| Reject long `Named_CalleeOf_Mission_*` as canonical; keep `_Inferred` | **Appropriate** |
| Dual A (fidelity) + B (adversarial attack table) both **accept** | **Appropriate** — B falsifies replace/invert/cdecl/bool/bounds/CRT-call/non-leaf cleanly |
| AutoCore port note: client path suffix only; no server play authority | **Sound** |
| Product/`_lxx` English open; host type identity beyond shared `+0x308` open; who writes flag open; runtime/diff open | **Fair residual** (dual already flags) |

---

## Adversarial attack results (independent)

| # | Attack | Result |
|---|---|---|
| 1 | Flag polarity inverted (0 = `_lxx`) | **Fails** — zero path loads `.ogg` only |
| 2 | cdecl / bare `RET` | **Fails** — `C2 04 00` |
| 3 | Replaces existing extension | **Fails** — end-of-string append only |
| 4 | Returns success bool | **Fails** — void; callers ignore EAX |
| 5 | Always a distinct CSoundManager heap instance | **Nuanced (dual-correct)** — Probe this vs audio-table singleton; shared `+0x308` sealed |
| 6 | Bounds-checks buffer | **Fails** |
| 7 | Calls CRT `strcat` | **Fails** — inline strlen + `rep movs*` |
| 8 | Dual body hex wrong vs image | **Fails** — independent 78 B match |
| 9 | Wrong string VAs / ASCII | **Fails** — both literals match |
| 10 | Xref count wrong | **Fails** — live 6 ≡ dual |

**No factual sealed-claim errors found** in report, A, B, raw append, annotated, cleans, or function records.

---

## Residual gaps (honest; dual already flags)

1. Product/PDB English for the helper; semantic meaning of **`_lxx`**.  
2. Whether `Client_GetMissionCompleteAudioTable` return (`&DAT_00d20210`) is the same C++ type as Probe’s CSoundManager, or only shares the `+0x308` flag layout.  
3. Who writes `host+0x308` (init / options / locale pack).  
4. Runtime / bit-exact / image differential (terminal coverage false; no Launcher).  
5. Stale Ghidra signature `FUN_00722790(void)` vs recovered thiscall — dual hygiene already privileges decompile + bytes (not a dual failure).

---

## Dual quality verdict (not bare LGTM)

### `aa_00722790` — **PASS** (`accept` stands)

Strengths:

- Leaf contract fully sealed from **bytes** (flag offset, polarity, both string VAs, `RET 4`, leaf, append mechanics).  
- A/B roles independent: A fidelity table; B attack table falsifies the high-risk inversions (polarity, replace-vs-append, ABI, return type).  
- Host-type nuance handled honestly (CSoundManager this vs GetMissionCompleteAudioTable singleton) without over-claiming product type identity.  
- Artifact chain coherent: raw scaffold preserved + W38-AG re-verify append; annotated; named clean + twin; function records; report.  
- Clean avoids inventing strip/alloc/FS/return codes.  
- Port guidance correctly scopes client path-resolution only.

Defects:

- **None** on sealed CF/ABI/string/xref claims under independent re-verify.

Process:

| Dimension | Assessment |
|---|---|
| Dual A+B present | Yes |
| Bytes win over decompiler phantom types | Yes (`int` params → host*/pathBuf) |
| Terminal coverage honesty | Sound (false / deferred) |
| OWN-ONLY / no parent ledger (claimed) | Outside rewrite scope of this verifier |
| Spot-check vs live Ghidra | Clean match |

---

## Summary

| VA | Dual quality | Verdict retention | Action |
|----|--------------|-------------------|--------|
| `0x00722790` | **PASS** | keep **accept** | none required |

**ADV artifact written:**

- `docs/reconstruction/reviews/ADV_wave38_spotcheck_00722790.md` (this file)
