# Review A (reconstruction fidelity): `aa_0094a6a0` Client_InitInstance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094a6a0` |
| **VA** | `0x0094a6a0`–`0x0094b324` |
| **Canonical name** | `Client_InitInstance` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (client InitInstance orchestration) |
| **Counterpart** | `reviews/B_aa_0094a6a0_Client_InitInstance.md` |
| **System** | `client-boot` |
| **Verdict** | **accept-with-gaps** — ABI/phase order/product strings/gates sealed; manager class English + flag English open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers. No `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

Client application **InitInstance**: fixed-order subsystem bring-up from crypto/COM through render/map/assets/clonebase/data tables/physics/sound/UI. Success returns **1**. Graphics failure **`_exit(1)`**.

Not "only clonebase table init" — tables are one gated phase inside full boot.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (full body + re-verify) | `docs/reconstruction/raw/aa_0094a6a0_FUN_0094a6a0.md` |
| Named raw | `docs/reconstruction/raw/aa_0094a6a0_Client_InitInstance.md` |
| Annotated | `docs/reconstruction/raw/aa_0094a6a0_Client_InitInstance.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InitInstance.cpp` |
| Function record | `docs/reconstruction/functions/aa_0094a6a0_Client_InitInstance.md` |
| Live decompile | `decompile_function` `0x0094a6a0` ≡ raw |
| Live bytes | entry SEH + exit `RET 4` / `return 1` |
| Callers | sole `FUN_0094ba40` |
| Context (read-only) | caller decompile shows `&DAT_00d1a840` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Frame | EBP + SEH (`LAB_009bbed0`) |
| Arg | **1 stack arg** client object (`[ebp+8]`) |
| Return cleanup | **`C2 04 00`** = **`RET 4`** → **`__stdcall`** |
| Success return | **`mov eax,1`** then epilogue |
| Body | `0x0094a6a0`–`0x0094b324` |
| Classification | **worker** (many callees) |

```c
uint32_t __stdcall Client_InitInstance(void *clientApp);
```

### 3.2 Product name — **SEALED (High)**

| String | Role |
|---|---|
| `"Client InitInstance"` | entry banner |
| `"@@Finish of InitInstance"` | late banner |
| `"InitInstance::done"` | done log |
| `"@@new CVOGSectorMap"` / `"@@InitRenderEngine"` / `"@@InitPhysics"` / `"@@InitSound"` / `"@@InitUserInterface"` / `"@@new CCloneBaseList"` | phase banners |

### 3.3 Phase order — **SEALED**

Live decompile **≡** 2026-07-23 raw (no CF delta). Order:

1. Entry / optional LED_FX  
2. Early managers + CVOGClonedObjectList + NDCrypto + CoInit/ini  
3. Render engine + sound + mission audio flags  
4. Sector map  
5. Asset manager / CNDAssetCatalog (RTTI replace)  
6. InitRenderEngine (**fail → _exit**)  
7. WorldInitialize + splash + optional dicts  
8. Gated asset post-init (`+0x31f5==0`)  
9. CloneBaseList + **gated** XP/credits/loot/medal ensures  
10. Physics + gated generators  
11. Sound + UI  
12. Finish: QPC, flags, optional LED teardown, **return 1**

### 3.4 Gate `+0x31f5` — **SEALED** (behavior; English open)

When **`*(char*)(app+0x31f5) == 0`**:

- Extra `NDXml_GetLoaderSingleton` post-init call  
- Table ensure batch (medals, creature/level/quest XP, quest credits lookup/base, loot rarity, …)  
- `m_pMap->InitGenerators`

When **nonzero**: those skipped; clonebase host still constructed (ctor receives the flag byte).

### 3.5 Caller — **SEALED**

Single xref from `FUN_0094ba40` @ `0x0094bd1a`:

```
iVar5 = FUN_0094a6a0(&DAT_00d1a840);
if (iVar5 != 0) { /* main loop path */ }
```

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ABI stdcall / RET 4 / return 1 | **High** | exit bytes |
| Name Client_InitInstance | **High** | product strings |
| Phase order | **High** | decompile ≡ raw |
| Gate +0x31f5 behavior | **High** | three sites |
| Gate English name | **Open** | design residual |
| Each manager class English | **Tentative** | strings seal map/render/UI phases |
| Server port need | **None** | client-only boot |

---

## 5. Open questions

1. Product C++ type of `DAT_00d1a840` / `param_1`.
2. English for `+0x31f5` (skip-data / editor / dedicated?).
3. Full English inventory of all `operator_new` products.
4. Runtime phase timing / failure modes beyond graphics `_exit`.
5. Interaction with non-developer entry paths (this caller is behind `-developer` check in `FUN_0094ba40` — residual on caller).

**Verdict:** **accept-with-gaps** — boot orchestration CF sealed; residual is type English depth, not control flow.
